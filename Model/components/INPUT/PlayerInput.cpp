
#include "PlayerInput.hpp"

using namespace components;

PlayerInput::PlayerInput(std::string name) :
    GenericInput(name), moveUp(false), moveDown(false), 
    moveLeft(false), moveRight(false) {}

void PlayerInput::processKeyInput(sf::Keyboard::Key key, bool isPressed){
    switch(key){
        case PLAYER_UP:
            this->moveUp = isPressed;
            break;
        case PLAYER_LEFT:
            this->moveLeft = isPressed;
            break;
        case PLAYER_DOWN:
            this->moveDown = isPressed;
            break;
        case PLAYER_RIGHT:
            this->moveRight = isPressed;
            break;
        case PLAYER_SHOOT:
            this->spacePress = isPressed;
            break;
    }
}

void PlayerInput::processMousePress(sf::Event::MouseButtonEvent buttonEvent, bool isPressed){}

bool PlayerInput::getUp(){
    return this->moveUp ;
}   

bool PlayerInput::getDown(){
    return this->moveDown ;
}

bool PlayerInput::getLeft(){
    return this->moveLeft ;
}

bool PlayerInput::getRight(){
    return this->moveRight ;
}

bool PlayerInput::getSpace(){
    return this->spacePress ;
}

void PlayerInput::resetSpace(){
    this->spacePress = false ;
}