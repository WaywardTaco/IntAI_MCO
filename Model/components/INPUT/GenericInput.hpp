
#pragma once

#include <SFML/Graphics.hpp>
#include "../Component.hpp"

namespace components {
    class GenericInput : public Component {
        protected:
            sf::Event event;
            sf::Vector2f vecLocation;

        public:
            GenericInput(std::string name);

            virtual void processKeyInput(sf::Keyboard::Key key, bool isPressed) = 0;
            virtual void processMousePress(sf::Event::MouseButtonEvent buttonEvent, bool isPressed) = 0;

            virtual void perform();
            void assignEvent(sf::Event event);
    };
}