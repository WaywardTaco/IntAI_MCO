
#pragma once

#include "GenericInput.hpp"

namespace components {
    class ResultsPromptInput : public GenericInput {
        private:
            bool   
                escapePressed;

        public:
            ResultsPromptInput(std::string name);

            void processKeyInput(sf::Keyboard::Key key, bool isPressed);
            void processMousePress(sf::Event::MouseButtonEvent buttonEvent, bool isPressed);

            bool isEscapePressed();
            void resetEscapePress();
    };
}