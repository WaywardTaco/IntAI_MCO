
#include "PlayerShipMoveInput.hpp"

using namespace components;

PlayerShipMovementInput::PlayerShipMovementInput(std::string name) : MovementInput(name) {}


void PlayerShipMovementInput::processKeyInput(sf::Keyboard::Key key, bool isPressed){
    switch(key){
        case sf::Keyboard::W:
            this->moveUp = isPressed;
            break;
        case sf::Keyboard::A:
            this->moveLeft = isPressed;
            break;
        case sf::Keyboard::S:
            this->moveDown = isPressed;
            break;
        case sf::Keyboard::D:
            this->moveRight = isPressed;
            break;
        case sf::Keyboard::Space:
            this->spacePress = isPressed;
            break;
    }
}

void PlayerShipMovementInput::processMousePress(sf::Event::MouseButtonEvent buttonEvent, bool isPressed){}