
#pragma once

#include "GenericInput.hpp"

namespace components {
    class ArenaPromptInput : public GenericInput {
        private:
            bool   
                escapePressed;

        public:
            ArenaPromptInput(std::string name);

            void processKeyInput(sf::Keyboard::Key key, bool isPressed);
            void processMousePress(sf::Event::MouseButtonEvent buttonEvent, bool isPressed);

            bool isEscapePressed();
            void resetEscapePressed();
    };
}