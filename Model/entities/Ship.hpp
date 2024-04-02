
#pragma once

#include "../../Config/BalanceSettings.hpp"
#include "../enums/ObjectTeams.hpp"
#include "../enums/FacingDir.hpp"
#include "TeamMember.hpp"
#include "../components/INPUT/PlayerInput.hpp"
#include "../components/SCRIPT/PlayerShipActions.hpp"
#include "../../Controller/Utility.hpp"

namespace entities {
    using namespace components;
    using namespace controllers;
    class Ship : public TeamMember {
        private:
            FacingDir facing;
            sf::Vector2f spawnCoords;

        public:
            Ship(std::string name, ObjectTeams team, sf::Vector2f spawnCoords);
            virtual void initialize();
            virtual void kill();

            void setFacing(FacingDir direction);
            FacingDir getFacing();
    };
}