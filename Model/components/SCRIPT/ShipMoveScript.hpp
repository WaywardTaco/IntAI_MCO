
#pragma once

#include <iostream>
#include "../../../Config/BalanceSettings.hpp"
#include "../../../Controller/managers/ObjectPoolManager.hpp"
#include "GenericScript.hpp"
#include "../INPUT/MovementInput.hpp"

namespace components {
    using namespace managers;
    class ShipMoveScript : public GenericScript {
        public:
            ShipMoveScript(std::string name);
            void perform();
    };
}