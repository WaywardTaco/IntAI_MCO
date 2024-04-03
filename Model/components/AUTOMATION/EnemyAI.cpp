
#include "EnemyAI.hpp"

using namespace components;

EnemyAI::EnemyAI(std::string name) : 
    GenericScript(name),
    nextDirection(FacingDir::NONE),
    shooting(false),
    elapsedTime(2.f)
    {
        this->nPlayerBases = (int) ObjectManager::Instance()->getObjects(ObjectType::BASE).size() / 2;
        std::vector<GameObject*> vecPlayerBases;
        for(int i = 0; i < nPlayerBases; i++) {
        vecPlayerBases.push_back(ObjectManager::Instance()->findObjectByName("BaseP" + std::to_string(i)));
        }
        this->vecPlayerBases = vecPlayerBases;
    };

void EnemyAI::perform(){
    this->elapsedTime += this->deltaTime.asSeconds();
    if(this->elapsedTime < 0.3f)
        return;

    this->EnemyPos = ObjectManager::Instance()->getObjects(ObjectType::SHIP)[0]->getPosition();
    this->Ship1Pos = ObjectManager::Instance()->getObjects(ObjectType::SHIP)[1]->getPosition();

    sf::Vector2f BaseDis, ClosestBaseDis{99999,99999}, PlayerShipDis = EnemyPos - Ship1Pos;
    int nClosestBaseNum = 0;
    for(int i = 0; i < nPlayerBases; i++) {
        if(vecPlayerBases[i]->getFrame() != 2) {
            BaseDis = EnemyPos - vecPlayerBases[i]->getPosition();

            if(lessDistance(BaseDis, ClosestBaseDis)) {
                ClosestBaseDis = BaseDis;
                nClosestBaseNum = i;
            }
        }
    }

    if(inDistance(shootDis))
       this->shooting = true;
    else this->shooting = false;

    if(vecPlayerBases[nClosestBaseNum]->getFrame() == 1) {
        //std::cout << "Player" << std::endl;
        MoveTo(PlayerShipDis);
    }
    else if(lessDistance(ClosestBaseDis, PlayerShipDis)) {
        //std::cout << "base" << std::endl;
        MoveTo(ClosestBaseDis);
    }
    else if(inDistance(viewDis)) {
        //std::cout << "Player" << std::endl;
        MoveTo(PlayerShipDis);
    }
    else {
        //std::cout << "base" << std::endl;
        MoveTo(ClosestBaseDis);
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

bool EnemyAI::lessDistance(sf::Vector2f disOne, sf::Vector2f disTwo) {
    if(disOne.x*disOne.x + disOne.y*disOne.y < disTwo.x*disTwo.x + disTwo.y*disTwo.y)
       return true;
    return false;
}