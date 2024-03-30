
#pragma once

#include "Ship.hpp"
#include "../components/SCRIPT/MatchTrackerScript.hpp"

namespace entities {
    using namespace components;
    class EnemyShip : public Ship {
        public:
            EnemyShip(std::string name);
            void initialize();
            void kill();
    };
}