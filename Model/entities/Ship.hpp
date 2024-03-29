
#pragma once

#include "../../Config/BalanceSettings.hpp"
#include "../enums/ObjectTeams.hpp"
#include "Entity.hpp"
#include "../components/INPUT/PlayerInput.hpp"
#include "../components/SCRIPT/PlayerShipActions.hpp"

namespace entities {
    using namespace components;
    class Ship : public Entity {
        public:
            Ship(std::string name, ObjectTeams team);
            virtual void initialize();
    };
}