
#pragma once

#include <SFML/Graphics.hpp>
#include "../Component.hpp"

namespace components {
    class GenericInput : public Component {
        private:
            sf::Event Event;

        public:
            GenericInput(std::string name, GameObject* owner);

            virtual void perform();
            void assignEvent(sf::Event event);

    };
}