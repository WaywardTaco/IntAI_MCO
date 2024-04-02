
#pragma once

#include "../../Config/BalanceSettings.hpp"
#include "Ship.hpp"
#include "Bullet.hpp"
#include "../components/INPUT/PlayerInput.hpp"
#include "../components/SCRIPT/PlayerShipActions.hpp"
#include "../components/SCRIPT/MatchTrackerScript.hpp"

namespace entities {
    using namespace components;
    class PlayerShip : public Ship {
        public:
            PlayerShip(std::string name, sf::Vector2f spawnCoords);
            void initialize();
            void kill();
    };
}