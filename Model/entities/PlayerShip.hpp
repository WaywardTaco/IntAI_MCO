
#pragma once

#include "../../Config/BalanceSettings.hpp"
#include "Entity.hpp"
#include "../components/INPUT/PlayerInput.hpp"
#include "../components/SCRIPT/PlayerShipActions.hpp"

namespace entities {
    using namespace components;
    class PlayerShip : public Entity {
        public:
            PlayerShip(std::string name);
            void initialize();
    };
}