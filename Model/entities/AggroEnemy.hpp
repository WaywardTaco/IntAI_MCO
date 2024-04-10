
#pragma once

#include "EnemyShip.hpp"

namespace entities {
    class AggroEnemy : public EnemyShip {
        public:
            AggroEnemy(std::string name, sf::Vector2f spawnCoords);
            void initialize();
    };
}