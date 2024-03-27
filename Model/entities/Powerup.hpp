
#pragma once

#include "Entity.hpp"
#include "../enums/PowerupType.hpp"
#include "../enums/ObjectType.hpp"

#include "../../View/AnimateTexture.hpp"
#include "../../Controller/managers/TextureManager.hpp"

namespace entities{
    using namespace view;
    using namespace managers;
    class Powerup : public Entity {
        protected:
            PowerupType type;

        public:
            Powerup(std::string name, PowerupType type);
            void initialize();
            GameObject* copy();
    };
}