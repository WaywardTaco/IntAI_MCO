
#pragma once

#include "EnemyShip.hpp"

namespace entities {
    class DefenseEnemy : public EnemyShip {
        public:
            DefenseEnemy(std::string name, sf::Vector2f spawnCoords);
            void initialize();
    };
}