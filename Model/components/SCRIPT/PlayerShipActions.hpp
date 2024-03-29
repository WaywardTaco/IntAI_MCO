
#pragma once

#include <iostream>
#include "../../../Config/BalanceSettings.hpp"
#include "../../../Controller/managers/ObjectPoolManager.hpp"
#include "GenericScript.hpp"
#include "../INPUT/PlayerInput.hpp"

namespace components {
    using namespace managers;
    class PlayerShipActions : public GenericScript {
        public:
            PlayerShipActions(std::string name);
            void perform();
    };
}