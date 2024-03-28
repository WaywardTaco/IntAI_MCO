
#pragma once

#include <vector>
#include "../Component.hpp"
#include "../../enums/ComponentType.hpp"
#include "../../../Controller/managers/ColliderManager.hpp"

namespace components{
    using namespace managers;
    class ColliderBase : public Component {
        private:
            float 
                xRadius,
                yRadius;
            bool hasCollisions;
            std::vector<ColliderBase*> collisions;

        public:
            ColliderBase(std::string name, sf::Sprite referenceSprite);
            ColliderBase(std::string name, float xRadius, float yRadius);

            void perform();

            void addCollision(ColliderBase* collider);
            void removeCollision(ColliderBase* collider);
            void removeAllCollisions();

            float getXRadius();
            float getYRadius();
            sf::Vector2f getPosition();

            std::vector<ColliderBase*> getCollisions();
            bool hasColliding();
    };
}