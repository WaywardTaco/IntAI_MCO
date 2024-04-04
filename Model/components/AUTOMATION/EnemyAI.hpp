
#pragma once

#include "../SCRIPT/GenericScript.hpp"
#include "../../enums/ComponentType.hpp"
#include "../../enums/ObjectType.hpp"
#include "../../enums/FacingDir.hpp"
#include "../../enums/EnemyState.hpp"
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
            int nBases;
            std::vector<GameObject*> vecPlayerBases;
            std::vector<GameObject*> vecEnemyBases;
            std::vector<GameObject*> vecPowerUps;
            sf::Vector2f EnemyPos;
            sf::Vector2f Ship1Pos;

            EnemyState nextMove = EnemyState::BASE_CHASE;
            sf::Vector2f EBCPDis;
            sf::Vector2f ClosestBaseDis;
            sf::Vector2f PlayerShipDis;
            sf::Vector2f ClosestChaosDis;
            sf::Vector2f ClosestInvinDis;
            int nEBCPNum;
            int nClosestBaseNum;

        public:
            EnemyAI(std::string name);
            void perform();

            FacingDir moveDirection();
            bool isShooting();
            void resetShooting();
            void MoveTo(sf::Vector2f DisToObj);
            bool inDistance(float Distance);
            float getDistance(sf::Vector2f distance);
            bool lessDistance(sf::Vector2f first, sf::Vector2f second);
            void BASE_CHASE();
            void BASE_PROTECTION();
            void PICKUP_MODE();
            void PLAYER_CHASE();
    };
}