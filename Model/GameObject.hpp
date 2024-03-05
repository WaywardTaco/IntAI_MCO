
#pragma once

#include <unordered_map>
#include <vector>
#include <SFML/Graphics.hpp>
#include "enums/ObjectType.hpp"
#include "enums/ComponentType.hpp"
#include "components/Component.hpp"
#include "../View/AnimateTexture.hpp"

namespace models {
    using namespace components;
    using namespace view;
    class GameObject{
        private:
            std::vector<Component*> components;
            std::string name;
            ObjectType type;
            sf::Sprite* sprite;
            AnimateTexture* texture;
            sf::Vector2f position;
            bool enabled;

        public:
            GameObject(std::string name, ObjectType type);

            virtual void initialize() = 0;

            void attachComponent(Component* component);
            void detachComponent(Component* component);

            std::vector<Component*> getComponents(ComponentType type);
            Component* getComponent(std::string name);
            std::string getName();
            ObjectType getType();
            sf::Sprite* getSprite();
            void setSprite(sf::Sprite* sprite);
            void setTexture(AnimateTexture* texture);
            sf::Vector2f getPosition();
            void setPosition(sf::Vector2f position);
            bool isEnabled();
            void enable();
            void disable();
    };
}