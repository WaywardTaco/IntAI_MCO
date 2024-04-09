
#pragma once

#include "Entity.hpp"
#include "../enums/PowerupType.hpp"
#include "../enums/ObjectType.hpp"
#include "../components/COLLIDER/ColliderBase.hpp"
#include "../components/SCRIPT/PowerupScript.hpp"

#include "../../View/AnimateTexture.hpp"
#include "../../Controller/managers/TextureManager.hpp"

namespace entities{
    using namespace view;
    using namespace managers;
    class Powerup : public Entity {
        protected:
            PowerupType powerupType;

        public:
            Powerup(std::string name, PowerupType powerupType);
            void initialize();
            GameObject* copy();

            void onRelease();

            PowerupType getPowerupType();
    };
}