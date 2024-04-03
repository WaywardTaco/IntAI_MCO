
#pragma once

#include "../SCRIPT/GenericScript.hpp"
#include "../../enums/ComponentType.hpp"
#include "../../enums/FacingDir.hpp"
#include "../../../Controller/Utility.hpp"

namespace components {
    using namespace controllers;
    class EnemyAI : public GenericScript {
        private:
            FacingDir nextDirection;
            bool shooting; 
            float elapsedTime;

        public:
            EnemyAI(std::string name);
            void perform();

            FacingDir moveDirection();
            bool isShooting();
            void resetShooting();
    };
}