
#pragma once

#include "EnemyShip.hpp"

namespace entities {
    class BalanceEnemy : public EnemyShip {
        public:
            BalanceEnemy(std::string name, sf::Vector2f spawnCoords);
            void initialize();
    };
}