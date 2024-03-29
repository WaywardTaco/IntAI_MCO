
#pragma once

#include "../GameObject.hpp"

namespace systems {
    using namespace models;
    class System : public GameObject {
        public:
            System(std::string name, ObjectType type);

            virtual void initialize() = 0;
            GameObject* copy();
    };
}