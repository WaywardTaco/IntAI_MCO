
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

    sf::Vector2f powerupDis, ClosestMineDis{99999,99999}, ClosestChaosDis{99999,99999}, ClosestInvinDis{99999,99999};
    int nClosestMineNum = 0, nClosestChaosNum = 0, nClosestInvinNum = 0;
    for(int i = 0; i < vecPowerUps.size(); i++) {
        if(vecPowerUps[i]->isEnabled()) {
            powerupDis = EnemyPos - vecPowerUps[i]->getPosition();
            switch(vecPowerUps[i]->getFrame()) {
                //SPACE_MINE Powerup
                case 0 : if(lessDistance(powerupDis, ClosestMineDis)) ClosestMineDis = powerupDis;
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
        case EnemyState::BASE_CHASE : BASE_CHASE();
        break;
        case EnemyState::BASE_PROTECTION : BASE_PROTECTION();
        break;
        case EnemyState::PICKUP_MODE : PICKUP_MODE();
        break;
        case EnemyState::PLAYER_CHASE : PLAYER_CHASE();
        break;
    }

    this->shooting = false;
    if(inDistance(shootDis)) {
        if(this->nextDirection == FacingDir::LEFT && PlayerShipDis.x > 0)
            this->shooting = true;
        else if(this->nextDirection == FacingDir::RIGHT && PlayerShipDis.x < 0)
            this->shooting = true;
        
        if(this->nextDirection == FacingDir::UP && PlayerShipDis.y > 0)
            this->shooting = true;
        else if(this->nextDirection == FacingDir::DOWN && PlayerShipDis.y < 0)
            this->shooting = true;
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

bool EnemyAI::inDistance(float Distance) {
    if(this->Ship1Pos.x >= (this->EnemyPos.x - Distance) && 
       this->Ship1Pos.x <= (this->EnemyPos.x + Distance) &&
       this->Ship1Pos.y >= (this->EnemyPos.y - Distance) && 
       this->Ship1Pos.y <= (this->EnemyPos.y + Distance) )
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
    else if(inDistance(viewDis)) {
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
    if(inDistance(viewDis)) MoveTo(PlayerShipDis);
    else {
        this->nextMove = EnemyState::BASE_CHASE;
        MoveTo(ClosestBaseDis);
    }
}