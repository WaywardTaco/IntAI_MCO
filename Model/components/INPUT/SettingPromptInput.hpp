
#pragma once

#include "GenericInput.hpp"

namespace components {
    class SettingPromptInput : public GenericInput {
        private:
            bool   
                spacePressed,
                escapePressed,
                leftPressed,
                rightPressed;

        public:
            SettingPromptInput(std::string name);

            void processKeyInput(sf::Keyboard::Key key, bool isPressed);
            void processMousePress(sf::Event::MouseButtonEvent buttonEvent, bool isPressed);

            bool isSpacePressed();
            void resetSpacePressed();

            bool isEscapePressed();
            void resetEscapePressed();

            bool isLeftPressed();
            void resetLeftPressed();

            bool isRightPressed();
            void resetRightPressed();

    };
}