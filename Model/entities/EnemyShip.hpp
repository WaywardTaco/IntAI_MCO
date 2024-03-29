
#pragma once

#include "Ship.hpp"

namespace entities {
    class EnemyShip : public Ship {
        public:
            EnemyShip(std::string name);
            void initialize();
    };
}