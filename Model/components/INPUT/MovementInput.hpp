
#pragma once

#include "GenericInput.hpp"

namespace components {
    class MovementInput : public GenericInput {
        protected:
            bool
                moveUp,
                moveDown,
                moveLeft,
                moveRight,
                spacePress;
        public:
            MovementInput(std::string name);

            virtual void processKeyInput(sf::Keyboard::Key key, bool isPressed) = 0;
            virtual void processMousePress(sf::Event::MouseButtonEvent buttonEvent, bool isPressed) = 0;

            bool getUp();            
            bool getDown();
            bool getLeft();
            bool getRight();
            bool getSpace();

            void resetUp();
            void resetDown();
            void resetLeft();
            void resetRight();
            void resetSpace();
    };
}