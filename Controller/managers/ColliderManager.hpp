
#pragma once

#include <vector>
#include <cmath>
#include "../../Model/components/COLLIDER/ColliderBase.hpp"

namespace managers {
    class ColliderManager{
        private:
            std::vector<ColliderBase*> colliders;

        public:
            void processCollisions();

            void registerCollider(ColliderBase* collider);
            void clearAllColliders();

        /* SINGLETON CODE */
        private:
            static ColliderManager* SHARED_INSTANCE;
            ColliderManager();
            ColliderManager(const ColliderManager&);
            ColliderManager& operator = (const ColliderManager&);
        public:
            static ColliderManager* Instance();
    };
}