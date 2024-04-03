
#include "EnemyAI.hpp"

using namespace components;

EnemyAI::EnemyAI(std::string name) : 
    GenericScript(name),
    nextDirection(FacingDir::NONE),
    shooting(false),
    elapsedTime(2.f){};

void EnemyAI::perform(){
    this->elapsedTime += this->deltaTime.asSeconds();
    if(this->elapsedTime < 0.1f)
        return;

    sf::Vector2f 
    EnemyPos = ObjectManager::Instance()->findObjectByName("Enemy")->getPosition(),
    Ship1Pos = ObjectManager::Instance()->findObjectByName("Ship1")->getPosition(),
    PlayerShipDis = EnemyPos - Ship1Pos;

    float viewDist = BULLET_SPEED * BULLET_MAX_SECONDS + 50.0f;

    if(Ship1Pos.x >= (EnemyPos.x - viewDist) && 
       Ship1Pos.x <= (EnemyPos.x + viewDist) &&
       Ship1Pos.y >= (EnemyPos.y - viewDist) && 
       Ship1Pos.y <= (EnemyPos.y + viewDist) )
       ChasePlayer(PlayerShipDis);

    if(Utility::getRandomNumber(0, 1) == 1)
        this->shooting = !this->shooting;
    
    // switch(Utility::getRandomNumber(0, 4)){
    //     case 0:
    //         this->nextDirection = FacingDir::UP;
    //         break;
    //     case 1:
    //         this->nextDirection = FacingDir::DOWN;
    //         break;
    //     case 2:
    //         this->nextDirection = FacingDir::LEFT;
    //         break;
    //     case 3:
    //         this->nextDirection = FacingDir::RIGHT;
    //         break;
    //     case 4:
    //         this->nextDirection = FacingDir::NONE;
    //         break;
    // }

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

void EnemyAI::ChasePlayer(sf::Vector2f PlayerShipDis) {
    if(abs(PlayerShipDis.x) > abs(PlayerShipDis.y)) {
        if(PlayerShipDis.x > 0) this->nextDirection = FacingDir::LEFT;
        else if(PlayerShipDis.x < 0) this->nextDirection = FacingDir::RIGHT;
    }
    else {
        if(PlayerShipDis.y > 0) this->nextDirection = FacingDir::UP;
        else if(PlayerShipDis.y < 0) this->nextDirection = FacingDir::DOWN;
    }
}