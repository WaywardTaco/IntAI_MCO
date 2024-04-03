
#pragma once

#include "../SCRIPT/GenericScript.hpp"
#include "../../enums/ComponentType.hpp"
#include "../../enums/ObjectType.hpp"
#include "../../enums/FacingDir.hpp"
#include "../../../Controller/Utility.hpp"
#include "../../../Controller/managers/ObjectManager.hpp"
#include "../../../Config/BalanceSettings.hpp"

namespace components {
    using namespace controllers;
    class EnemyAI : public GenericScript {
        private:
            FacingDir nextDirection;
            bool shooting; 
            float elapsedTime;
            float shootDis = BULLET_SPEED * BULLET_MAX_SECONDS;
            float viewDis = shootDis + 50.0f;
            int nPlayerBases;
            std::vector<GameObject*> vecPlayerBases;
            sf::Vector2f EnemyPos;
            sf::Vector2f Ship1Pos;

        public:
            EnemyAI(std::string name);
            void perform();

            FacingDir moveDirection();
            bool isShooting();
            void resetShooting();
            void MoveTo(sf::Vector2f DisToObj);
            bool inDistance(float Distance);
            bool lessDistance(sf::Vector2f first, sf::Vector2f second);
    };
}