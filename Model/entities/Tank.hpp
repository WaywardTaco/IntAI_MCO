
#pragma once

#include "Entity.hpp"
#include "../components/INPUT/PlayerShipMoveInput.hpp"
#include "../components/SCRIPT/ShipMoveScript.hpp"

namespace entities {
    using namespace components;
    class Tank : public Entity {
        public:
            Tank(std::string name);

            void initialize();
    };
}