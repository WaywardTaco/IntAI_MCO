
#pragma once

#include "MovementInput.hpp"

namespace components {
    class PlayerShipMovementInput : public MovementInput {
        public:
            PlayerShipMovementInput(std::string name);

            virtual void processKeyInput(sf::Keyboard::Key key, bool isPressed);
            virtual void processMousePress(sf::Event::MouseButtonEvent buttonEvent, bool isPressed);
    };
}