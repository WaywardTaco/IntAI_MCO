
#pragma once

#include "System.hpp"
#include "../ObjectPool.hpp"
#include "../components/SCRIPT/SpawnerScript.hpp"
#include "../../Controller/managers/ObjectPoolManager.hpp"

namespace systems{
    using namespace managers;
    using namespace components;
    class Spawner : public System {
        public: 
            ObjectPool* minePool;
            ObjectPool* chaosPool;
            ObjectPool* shieldPool;

        public:
            Spawner(std::string name, ObjectPool* minePool, ObjectPool* chaosPool, ObjectPool* shieldPool);

            void initialize();
            ObjectPool* getMinePool();
            ObjectPool* getChaosPool();
            ObjectPool* getShieldPool();
    };
}