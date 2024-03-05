
#pragma once

#include <SFML/Graphics.hpp>
#include "../Component.hpp"

namespace components {
    class GenericRenderer : public Component {
        public:
            virtual void perform();
            void assignWindow(sf::RenderWindow* window);
    };
}