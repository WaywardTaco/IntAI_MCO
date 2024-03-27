
#pragma once

#include "Entity.hpp"
#include "../components/INPUT/PlayerShipMoveInput.hpp"
#include "../components/SCRIPT/ShipMoveScript.hpp"

namespace entities {
    using namespace components;
    class Ship : public Entity {
        public:
            Ship(std::string name);
            void initialize();
    };
}