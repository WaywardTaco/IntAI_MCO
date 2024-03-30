
#pragma once

#include "../../Config/BalanceSettings.hpp"
#include "../enums/ObjectTeams.hpp"
#include "TeamMember.hpp"
#include "../components/INPUT/PlayerInput.hpp"
#include "../components/SCRIPT/PlayerShipActions.hpp"
#include "../../Controller/Utility.hpp"

namespace entities {
    using namespace components;
    using namespace controllers;
    class Ship : public TeamMember {
        public:
            Ship(std::string name, ObjectTeams team);
            virtual void initialize();
            void kill();
    };
}