
#pragma once

#include <SFML/Graphics.hpp>

#include "Ship.hpp"
#include "../components/SCRIPT/MatchTrackerScript.hpp"
#include "../components/AUTOMATION/EnemyAI.hpp"
#include "../components/SCRIPT/EnemyShipActions.hpp"
#include "Bullet.hpp"
#include "../ObjectPool.hpp"

namespace entities {
    using namespace components;
    class EnemyShip : public Ship {
        public:
            EnemyShip(std::string name, sf::Vector2f spawnCoords);
            virtual void initialize();
            void kill();
    };
}