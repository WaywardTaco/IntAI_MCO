
#pragma once

#include "../enums/ObjectType.hpp"
#include "../enums/TextureType.hpp"
#include "../GameObject.hpp"
#include "../../Controller/managers/TextureManager.hpp"
#include "../../View/AnimateTexture.hpp"
#include "../components/RENDERER/GenericRenderer.hpp"

namespace entities {
    using namespace managers;
    using namespace models;
    using namespace view;
    using namespace components;
    class Entity : public GameObject {
        public:
            Entity();

            void initialize();
    };
}