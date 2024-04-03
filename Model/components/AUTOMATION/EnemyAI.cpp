
#include "EnemyAI.hpp"

using namespace components;

EnemyAI::EnemyAI(std::string name) : 
    GenericScript(name),
    nextDirection(FacingDir::NONE),
    shooting(false),
    elapsedTime(2.f){};

void EnemyAI::perform(){
    this->elapsedTime += this->deltaTime.asSeconds();
    if(this->elapsedTime < 2.f)
        return;

    if(Utility::getRandomNumber(0, 1) == 1)
        this->shooting = !this->shooting;
    
    switch(Utility::getRandomNumber(0, 4)){
        case 0:
            this->nextDirection = FacingDir::UP;
            break;
        case 1:
            this->nextDirection = FacingDir::DOWN;
            break;
        case 2:
            this->nextDirection = FacingDir::LEFT;
            break;
        case 3:
            this->nextDirection = FacingDir::RIGHT;
            break;
        case 4:
            this->nextDirection = FacingDir::NONE;
            break;
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