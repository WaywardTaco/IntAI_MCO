
#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include "../Component.hpp"

namespace components {
    class GenericScript : public Component {
        protected:
            sf::Time deltaTime;

        public:
            GenericScript(std::string name, GameObject* owner);

            virtual void perform() = 0;
            void assignDeltaTime(sf::Time deltaTime);
    };
}