
#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include "../Component.hpp"

namespace components {
    class GenericRenderer : public Component {
        protected:
            sf::RenderWindow window;

        public:
            GenericRenderer(std::string name, GameObject* owner);

            virtual void perform();
            void assignWindow(sf::RenderWindow* window);
    };
}