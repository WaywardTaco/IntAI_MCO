
#pragma once

#include <string>
#include "../enums/ObjectType.hpp"
#include "../enums/TextureType.hpp"
#include "../../Controller/managers/TextureManager.hpp"
#include "../GameObject.hpp"
#include "../components/RENDERER/GenericRenderer.hpp"

namespace entities {
    using namespace components;
    using namespace managers;
    using namespace models;
    class Entity : public GameObject {
        public:
            Entity(std::string name, ObjectType type);

            virtual void initialize() = 0;
            virtual GameObject* copy();
    };
}