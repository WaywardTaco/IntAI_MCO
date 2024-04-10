
#pragma once

#include "GenericInput.hpp"
#include "../../../Config/ControlSettings.hpp"
#include "../../../Controller/managers/ControlManager.hpp"

namespace components {
    class PlayerInput : public GenericInput {
        protected:
            bool
                moveUp,
                moveDown,
                moveLeft,
                moveRight,
                spacePress;
        public:
            PlayerInput(std::string name);

            virtual void processKeyInput(sf::Keyboard::Key key, bool isPressed);
            virtual void processMousePress(sf::Event::MouseButtonEvent buttonEvent, bool isPressed);

            bool getUp();            
            bool getDown();
            bool getLeft();
            bool getRight();
            bool getSpace();

            void resetSpace();
    };
}