
#pragma once

#include <unordered_map>

#include "../../Model/enums/ObjectType.hpp"
#include "../../Model/ObjectPool.hpp"

namespace managers {
    class ObjectPoolManager {
        private:
            std::unordered_map<ObjectType, std::vector<ObjectPool*>> mapObjectPools;

        public:
            void registerPool(ObjectPool* objectPool);
            void clearAllPools();
            ObjectPool* getObjectPoolByName(std::string name);
            ObjectPool* getObjectPool(ObjectType tag);

        /* SINGLETON CODE */
        private:
            static ObjectPoolManager* SHARED_INSTANCE;
            ObjectPoolManager();
            ObjectPoolManager(const ObjectPoolManager&);
            ObjectPoolManager& operator = (const ObjectPoolManager&);
        public:
            static ObjectPoolManager* Instance();

    };
}