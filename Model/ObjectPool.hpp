
#pragma once

#include <vector>
#include "enums/ObjectType.hpp"
#include "../Controller/managers/ObjectManager.hpp"
#include "GameObject.hpp"

namespace models {
    using namespace managers;
    class ObjectPool {
        private:
            std::string name;
            ObjectType poolType;
            GameObject* refObject;
            int poolSize;
            std::vector<GameObject*> 
                availableObjects,
                usedObjects;

        public:
            ObjectPool(std::string name, int poolSize, GameObject* refObject);
            ~ObjectPool();

            void initialize();
            GameObject* getObject();
            std::vector<GameObject*> getObjects(int count);
            void releaseObject(GameObject* object);
            void releaseObjects(std::vector<GameObject*> vecObjects);
            ObjectType getPoolType();
            std::string getName();

            bool isEmpty();
    };
}