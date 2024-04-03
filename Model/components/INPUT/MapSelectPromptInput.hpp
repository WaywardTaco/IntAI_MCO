
#pragma once

#include "GenericInput.hpp"

namespace components {
    class MapSelectPromptInput : public GenericInput {
        private:
            bool
                prevMap,
                nextMap;
        public:
            MapSelectPromptInput(std::string name);

            void processKeyInput(sf::Keyboard::Key key, bool isPressed);
            void processMousePress(sf::Event::MouseButtonEvent buttonEvent, bool isPressed);

            bool isGoPrev();
            bool isGoNext();
            void resetFlags();
    };
}