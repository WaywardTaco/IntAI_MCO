
#pragma once

#include <SFML/Graphics.hpp>
#include "../Component.hpp"

namespace components {
    class GenericScript : public Component {
        public:
            virtual void perform();
            void assignDeltaTime(sf::Time deltaTime);
    };
}