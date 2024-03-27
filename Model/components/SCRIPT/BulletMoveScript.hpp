
#pragma once

#include "../../../Config/BalanceSettings.hpp"
#include "GenericScript.hpp"
#include "../../../Controller/managers/ObjectPoolManager.hpp"
#include "../COLLIDER/ColliderBase.hpp"

namespace components {
    using namespace managers;
    class BulletMoveScript : public GenericScript {
        private:
            float elapsedTime;

        public:
            BulletMoveScript(std::string name);
            void perform();
    };
}