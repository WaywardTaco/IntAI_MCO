
#pragma once

#include "GenericInput.hpp"

namespace components {
    class ResultsPromptInput : public GenericInput {
        private:
            bool   
                spacePressed;

        public:
            ResultsPromptInput(std::string name);

            void processKeyInput(sf::Keyboard::Key key, bool isPressed);
            void processMousePress(sf::Event::MouseButtonEvent buttonEvent, bool isPressed);

            bool isSpacePressed();
            void resetSpacePressed();
    };
}