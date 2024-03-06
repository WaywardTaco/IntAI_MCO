
#pragma once

#include <iostream>
#include "GenericScript.hpp"
#include "../INPUT/MovementInput.hpp"

namespace components {
    class ShipMoveScript : public GenericScript {
        public:
            ShipMoveScript(std::string name);

            void perform();
    };
}