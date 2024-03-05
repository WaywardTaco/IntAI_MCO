
#pragma once

#include <SFML/Graphics.hpp>
#include "../Component.hpp"

namespace components {
    class GenericInput : public Component {
        private:
            sf::Event event;

        public:
            GenericInput(std::string name);

            virtual void processKeyInput(sf::Keyboard::Key key, bool isPressed) = 0;

            virtual void perform();
            void assignEvent(sf::Event event);
    };
}