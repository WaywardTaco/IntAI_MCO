
#pragma once

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "../Component.hpp"

namespace components {
    class GenericRenderer : public Component {
        protected:
            sf::RenderWindow* window;
            std::vector<sf::Drawable*> drawables;

        public:
            GenericRenderer(std::string name);

            virtual void perform();
            void assignWindow(sf::RenderWindow* window);
            void assignDrawable(sf::Drawable* drawable);
    };
}