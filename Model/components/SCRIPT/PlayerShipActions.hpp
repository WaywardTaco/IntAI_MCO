
#pragma once

#include <iostream>
#include "../../../Config/BalanceSettings.hpp"
#include "../../../Controller/managers/ObjectPoolManager.hpp"
#include "GenericScript.hpp"
#include "../INPUT/PlayerInput.hpp"
#include "../../enums/FacingDir.hpp"
#include "../../entities/Ship.hpp"

namespace components {
    using namespace entities;
    using namespace managers;
    class PlayerShipActions : public GenericScript {
        public:
            PlayerShipActions(std::string name);
            void perform();
    };
}