
#pragma once

#include <unordered_map>
#include <vector>
#include <SFML/Graphics.hpp>
#include "enums/ObjectType.hpp"
#include "enums/ComponentType.hpp"
#include "../Controller/managers/TextureManager.hpp"
#include "components/Component.hpp"
#include "../View/AnimateTexture.hpp"

namespace models {
    using namespace components;
    using namespace view;
    class GameObject{
        protected:
            GameObject* parent;
            std::vector<GameObject*> children;
            std::vector<Component*> components;
            std::string name;
            ObjectType type;
            sf::Sprite* sprite;
            AnimateTexture* texture;
            sf::Vector2f position;
            bool enabled;

        public:
            GameObject(std::string name, ObjectType type);
            virtual GameObject* copy();

            virtual void initialize() = 0;
            virtual void onActivate();
            virtual void onRelease();

            void attachComponent(Component* component);
            void detachComponent(Component* component);

            void attachParent(GameObject* parent);
            void detachParent();
            GameObject* getParent();

            void centerOrigin();
            void iterateFrames();
            void setFrame(int frame);

            std::vector<Component*> getComponents(ComponentType type);
            Component* getComponent(std::string name);
            std::string getName();
            ObjectType getType();
            sf::Sprite* getSprite();
            void setSprite(sf::Sprite* sprite);
            void setTexture(AnimateTexture* texture);
            sf::Vector2f getPosition();
            float getRotation();
            void setPosition(sf::Vector2f position);
            void movePosition(sf::Vector2f position);
            sf::FloatRect getBounds();
            bool isEnabled();
            void enable();
            void disable();
    };
}