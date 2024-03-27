
#include "MovementInput.hpp"

using namespace components;
MovementInput::MovementInput(std::string name) :
    GenericInput(name), moveUp(false), moveDown(false), 
    moveLeft(false), moveRight(false) {}

bool MovementInput::getUp(){
    return this->moveUp ;
}   

bool MovementInput::getDown(){
    return this->moveDown ;
}

bool MovementInput::getLeft(){
    return this->moveLeft ;
}

bool MovementInput::getRight(){
    return this->moveRight ;
}

bool MovementInput::getSpace(){
    return this->spacePress ;
}

void MovementInput::resetUp(){
    this->moveUp = false ;
}

void MovementInput::resetDown(){
    this->moveDown = false ;
}

void MovementInput::resetLeft(){
    this->moveLeft = false ;
}

void MovementInput::resetRight(){
    this->moveRight = false ;
}

void MovementInput::resetSpace(){
    this->spacePress = false ;
}