
#pragma once

#include "GenericScript.hpp"
#include "../../../Config/GameSettings.hpp"
#include "../../enums/ObjectType.hpp"
#include "../../enums/PowerupType.hpp"
#include "../COLLIDER/ColliderBase.hpp"
#include "../../entities/Ship.hpp"
#include "../../entities/Base.hpp"
#include "../../entities/Powerup.hpp"
#include "../../../Controller/managers/AudioManager.hpp"

namespace components{
    using namespace managers;
    using namespace entities;
    class PowerupScript : public GenericScript {
        private:
            float elapsedTime;
            sf::Vector2f driftVec;

        public:
            PowerupScript(std::string name);
            void perform();
        private:
            void chaosEffect(Ship* ship);
            void shieldEffect(Ship* ship);
            void mineEffect(Ship* ship);
    };
}