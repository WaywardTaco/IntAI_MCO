
#pragma once

#include <iostream>
#include "../../../Config/BalanceSettings.hpp"
#include "../../../Config/GameSettings.hpp"
#include "../../../Controller/managers/ObjectPoolManager.hpp"
#include "GenericScript.hpp"
#include "../../enums/FacingDir.hpp"
#include "../../entities/Ship.hpp"
#include "../AUTOMATION/EnemyAI.hpp"

namespace components {
    using namespace entities;
    using namespace managers;
    class EnemyShipActions : public GenericScript {
        private:
            float shootingElapsed;

        public:
            EnemyShipActions(std::string name);
            void perform();
    };
}