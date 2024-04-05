
#pragma once

#include "GenericInput.hpp"

namespace components {
    class QuitPromptInput : public GenericInput {
        private:
            bool   
                spacePressed,
                escapePressed;

        public:
            QuitPromptInput(std::string name);

            void processKeyInput(sf::Keyboard::Key key, bool isPressed);
            void processMousePress(sf::Event::MouseButtonEvent buttonEvent, bool isPressed);

            bool isSpacePressed();
            void resetSpacePressed();

            bool isEscapePressed();
            void resetEscapePressed();

    };
}