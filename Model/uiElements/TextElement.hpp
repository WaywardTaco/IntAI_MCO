
#pragma once

#include "../GameObject.hpp"
#include "../enums/ObjectType.hpp"
#include "../components/RENDERER/GenericRenderer.hpp"

namespace uiElements {
    using namespace components;
    using namespace models;
    class TextElement : public GameObject {
        private:
            sf::Text* sfText;

        public: 
            TextElement(std::string name, std::string text, sf::Font* font, int fontSize, ObjectType type);
            virtual void initialize();
            
            void setText(std::string text, bool centerOrigin);
            void setPosition(sf::Vector2f position);
    };
}