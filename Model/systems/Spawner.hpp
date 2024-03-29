
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
            ObjectPool* spawnPool;

        public:
            Spawner(std::string name, ObjectPool* spawnPool);

            void initialize();
            ObjectPool* getPool();
    };
}