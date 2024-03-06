
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
