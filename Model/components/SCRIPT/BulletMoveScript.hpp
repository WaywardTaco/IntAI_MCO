
#pragma once

#include "../../../Config/BalanceSettings.hpp"
#include "GenericScript.hpp"
#include "../../../Controller/managers/ObjectPoolManager.hpp"
#include "../COLLIDER/ColliderBase.hpp"
#include "../../entities/Ship.hpp"
#include "../../entities/Bullet.hpp"
#include "../../enums/FacingDir.hpp"

namespace components {
    using namespace entities;
    using namespace managers;
    class BulletMoveScript : public GenericScript {
        private:
            float elapsedTime;
            FacingDir facing;

        public:
            BulletMoveScript(std::string name);
            void perform();
            void setFacing(FacingDir direction);
    };
}