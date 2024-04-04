
#include "EnemyAI.hpp"

using namespace components;

EnemyAI::EnemyAI(std::string name) : 
    GenericScript(name),
    nextDirection(FacingDir::NONE),
    shooting(false),
    elapsedTime(2.f)
    {
        this->nBases = (int) ObjectManager::Instance()->getObjects(ObjectType::BASE).size() / 2;

        for(int i = 0; i < nBases; i++) {
        this->vecPlayerBases.push_back(ObjectManager::Instance()->findObjectByName("BaseP" + std::to_string(i)));
        }

        for(int i = 0; i < nBases; i++) {
        this->vecEnemyBases.push_back(ObjectManager::Instance()->findObjectByName("BaseE" + std::to_string(i)));
        }

        this->vecPowerUps = ObjectManager::Instance()->getObjects(ObjectType::POWERUP);
    };

void EnemyAI::perform(){
    this->elapsedTime += this->deltaTime.asSeconds();
    if(this->elapsedTime < 0.3f)
        return;

    this->EnemyPos = ObjectManager::Instance()->getObjects(ObjectType::SHIP)[0]->getPosition();
    this->Ship1Pos = ObjectManager::Instance()->getObjects(ObjectType::SHIP)[1]->getPosition();

    sf::Vector2f BaseDis, ClosestBaseDis{99999,99999};
    for(int i = 0; i < nBases; i++) {
        if(vecPlayerBases[i]->getFrame() != 2) {
            BaseDis = EnemyPos - vecPlayerBases[i]->getPosition();

            if(lessDistance(BaseDis, ClosestBaseDis)) {
                ClosestBaseDis = BaseDis;
                this->nClosestBaseNum = i;
            }
        }
    }

    sf::Vector2f powerupDis, MinePos, ClosestChaosDis{99999,99999}, ClosestInvinDis{99999,99999};
    int nClosestMineNum = 0, nClosestChaosNum = 0, nClosestInvinNum = 0;
    for(int i = 0; i < vecPowerUps.size(); i++) {
        if(vecPowerUps[i]->isEnabled()) {
            powerupDis = EnemyPos - vecPowerUps[i]->getPosition();
            switch(vecPowerUps[i]->getFrame()) {
                //SPACE_MINE Powerup
                case 0 : if(inDistance(vecPowerUps[i]->getPosition(), shootDis)) {
                    MinePos = vecPowerUps[i]->getPosition();
                    if(powerupDis.x > 0 && inDistance(MinePos, {this->shootDis, this->viewRange})) this->vecMineCD[0] = true;
                    else if(powerupDis.x < 0 && inDistance(MinePos, {this->shootDis, this->viewRange})) this->vecMineCD[1] = true;
                   
                    if(powerupDis.y > 0 && inDistance(MinePos, {this->viewRange, this->shootDis})) this->vecMineCD[2] = true;
                    else if(powerupDis.y < 0 && inDistance(MinePos, {this->viewRange, this->shootDis})) this->vecMineCD[3] = true;
                }
                break;

                //BASE_CHAOS Powerup
                case 1 : if(lessDistance(powerupDis, ClosestChaosDis)) ClosestChaosDis = powerupDis;
                break;
                
                //BASE_INVINCIBILITY Powerup
                case 2 : if(lessDistance(powerupDis, ClosestInvinDis)) ClosestInvinDis = powerupDis;
                break;
            }
        }
    }

    //EBCTP: Enemy Base Closest to Player
    sf::Vector2f EnemyBaseDis, EBCPDis{99999,99999};
    for(int i = 0; i < nBases; i++) {
        if(vecEnemyBases[i]->getFrame() != 2) {
            EnemyBaseDis = Ship1Pos - vecEnemyBases[i]->getPosition();

            if(lessDistance(EnemyBaseDis, EBCPDis)) {
                EBCPDis = EnemyBaseDis;
                this->nEBCPNum = i;
            }
        }
    }

    this->EBCPDis = EBCPDis;
    this->ClosestBaseDis = ClosestBaseDis;
    this->PlayerShipDis = EnemyPos - Ship1Pos;
    this->ClosestChaosDis = ClosestChaosDis;
    this->ClosestInvinDis = ClosestInvinDis;

    switch(this->nextMove) {
        case EnemyState::BASE_CHASE      : BASE_CHASE();
        break;
        case EnemyState::BASE_PROTECTION : BASE_PROTECTION();
        break;
        case EnemyState::PICKUP_MODE     : PICKUP_MODE();
        break;
        case EnemyState::PLAYER_CHASE    : PLAYER_CHASE();
        break;
    }

    if(inDistance(Ship1Pos, shootDis)) {
        if(PlayerShipDis.x > 0 && inDistance(Ship1Pos, {this->shootDis, this->viewRange})) this->vecShipCD[0] = true;
        else if(PlayerShipDis.x < 0 && inDistance(Ship1Pos, {this->shootDis, this->viewRange})) this->vecShipCD[1] = true;
                   
        if(PlayerShipDis.y > 0 && inDistance(Ship1Pos, {this->viewRange, this->shootDis})) this->vecShipCD[2] = true;
        else if(PlayerShipDis.y < 0 && inDistance(Ship1Pos, {this->viewRange, this->shootDis})) this->vecShipCD[3] = true;
    }

    this->shooting = false;
    switch(this->nextDirection) {
        case  FacingDir::LEFT  : if(this->vecShipCD[0] == true || this->vecMineCD[0] == true)
            this->shooting = true;
            break;
        case  FacingDir::RIGHT : if(this->vecShipCD[1] == true || this->vecMineCD[1] == true)
            this->shooting = true;
            break;
        case  FacingDir::UP    : if(this->vecShipCD[2] == true || this->vecMineCD[2] == true)
            this->shooting = true;
            break;
        case  FacingDir::DOWN  : if(this->vecShipCD[3] == true || this->vecMineCD[3] == true)
            this->shooting = true;
            break;
    }

    for(int i = 0; i < 4; i++) {
        this->vecMineCD[i] = false;
        this->vecShipCD[i] = false;
    }
    this->elapsedTime = 0.f;
}

FacingDir EnemyAI::moveDirection(){
    return this->nextDirection;
}

bool EnemyAI::isShooting(){
    return this->shooting;
}

void EnemyAI::resetShooting(){
    if(Utility::getRandomNumber(0, 6) > 0)
        this->shooting = false;
}

void EnemyAI::MoveTo(sf::Vector2f DisToObj) {
    if(abs(DisToObj.x) > abs(DisToObj.y)) {
        if(DisToObj.x > 0) this->nextDirection = FacingDir::LEFT;
        else if(DisToObj.x < 0) this->nextDirection = FacingDir::RIGHT;
    }
    else {
        if(DisToObj.y > 0) this->nextDirection = FacingDir::UP;
        else if(DisToObj.y < 0) this->nextDirection = FacingDir::DOWN;
    }
}

bool EnemyAI::inDistance(sf::Vector2f Position, float Distance) {
    if(Position.x >= (this->EnemyPos.x - Distance) && 
       Position.x <= (this->EnemyPos.x + Distance) &&
       Position.y >= (this->EnemyPos.y - Distance) && 
       Position.y <= (this->EnemyPos.y + Distance) )
       return true;
    return false;
}

bool EnemyAI::inDistance(sf::Vector2f Position, sf::Vector2f Distance) {
    if(Position.x >= (this->EnemyPos.x - Distance.x) && 
       Position.x <= (this->EnemyPos.x + Distance.x) &&
       Position.y >= (this->EnemyPos.y - Distance.y) && 
       Position.y <= (this->EnemyPos.y + Distance.y) )
       return true;
    return false;
}

float EnemyAI::getDistance(sf::Vector2f distance) {
    return distance.x*distance.x + distance.y*distance.y;
}

bool EnemyAI::lessDistance(sf::Vector2f disOne, sf::Vector2f disTwo) {
    if(getDistance(disOne) < getDistance(disTwo))
       return true;
    return false;
}

void EnemyAI::BASE_CHASE() {
    if(lessDistance(EBCPDis, {50,50}) && vecEnemyBases[nEBCPNum]->getFrame() == 0) {
        this->nextMove = EnemyState::BASE_PROTECTION;
    }
    else if(vecPlayerBases[nClosestBaseNum]->getFrame() == 1) {
        this->nextMove = EnemyState::PICKUP_MODE;
    }
    else if(inDistance(Ship1Pos, viewDis)) {
        this->nextMove = EnemyState::PLAYER_CHASE;
    }
    
    MoveTo(ClosestBaseDis);
}

void EnemyAI::BASE_PROTECTION() {
    if(lessDistance(EBCPDis, {50,50}) && vecEnemyBases[nEBCPNum]->getFrame() == 0) {
        sf::Vector2f shortestDis = PlayerShipDis;

        if(lessDistance(ClosestChaosDis, shortestDis))
            shortestDis = ClosestChaosDis;
        if(lessDistance(ClosestInvinDis, shortestDis))
            shortestDis = ClosestInvinDis;
        if(lessDistance(ClosestBaseDis, shortestDis) && vecPlayerBases[nClosestBaseNum]->getFrame() == 0)
            shortestDis = ClosestBaseDis;

        MoveTo(shortestDis);
    }
    else {
        this->nextMove = EnemyState::BASE_CHASE;
        MoveTo(ClosestBaseDis);
    }
}

void EnemyAI::PICKUP_MODE() {
    if(vecPlayerBases[nClosestBaseNum]->getFrame() == 1) {
        if(lessDistance(ClosestInvinDis, PlayerShipDis)) MoveTo(ClosestInvinDis);
        else MoveTo(PlayerShipDis);
    }
    else {
        this->nextMove = EnemyState::BASE_CHASE;
        MoveTo(ClosestBaseDis);
    }
}

void EnemyAI::PLAYER_CHASE() {
    if(inDistance(Ship1Pos, viewDis)) MoveTo(PlayerShipDis);
    else {
        this->nextMove = EnemyState::BASE_CHASE;
        MoveTo(ClosestBaseDis);
    }
}