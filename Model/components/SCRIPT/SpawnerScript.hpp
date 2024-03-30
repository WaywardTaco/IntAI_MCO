
#pragma once 

#include "GenericScript.hpp"
#include "../../ObjectPool.hpp"
#include "../../systems/Spawner.hpp"
#include "../../../Config/BalanceSettings.hpp"
#include "../../../Config/GameSettings.hpp"
#include "../../../Controller/Utility.hpp"

namespace components{
    using namespace systems;
    using namespace controllers;
    class SpawnerScript : public GenericScript {
        private:
            float elapsedTime;

        public:
            SpawnerScript(std::string name);
            void perform();
    };
}