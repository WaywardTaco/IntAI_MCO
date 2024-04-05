
#pragma once

#include "../SCRIPT/GenericScript.hpp"
#include "../../enums/ComponentType.hpp"
#include "../../enums/ObjectType.hpp"
#include "../../enums/FacingDir.hpp"
#include "../../enums/EnemyState.hpp"
#include "../../../Controller/Utility.hpp"
#include "../../../Controller/managers/ObjectManager.hpp"
#include "../../../Config/BalanceSettings.hpp"
#include "../../entities/Ship.hpp"
#include "../COLLIDER/ColliderBase.hpp"
#include "../SCRIPT/MatchTrackerScript.hpp"

namespace components {
    using namespace controllers;
    class EnemyAI : public GenericScript {
        private:
            FacingDir nextDirection;
            bool shooting; 
            float elapsedTime;
            float shootDis = BULLET_SPEED * BULLET_MAX_SECONDS;
            float viewDis = shootDis + 100.0f;
            float viewRange = 50.0f;
            float huntRange = 5.0f;
            float ShipArea = 50;
            int nBases;
            sf::Vector2f BaseRange{50, 50};
            std::vector<GameObject*> vecPlayerBases;
            std::vector<GameObject*> vecEnemyBases;
            std::vector<GameObject*> vecPowerUps;
            sf::Vector2f EnemyPos;
            sf::Vector2f Ship1Pos;

            EnemyState nextMove = EnemyState::BASE_CHASE;
            sf::Vector2f EBCPDis;
            sf::Vector2f ClosestBaseDis;
            sf::Vector2f PlayerShipDis;
            sf::Vector2f PtoBDis;
            sf::Vector2f ClosestChaosDis;
            sf::Vector2f ClosestInvinDis;
            int nEBCPNum;
            int nClosestBaseNum;
            int nClosestInvinNum = 0;
            float booleanVision = 1.00;
                                //Left, Right,    Up,  Down
            bool vecMineCD[4] = {false, false, false, false};
            bool vecShipCD[4] = {false, false, false, false};
                                    //Defense, Powerup, Offense
            float priorityPercent[3] = {50, 50, 50};
            sf::Vector2f heuristicValue = {priorityPercent[1], priorityPercent[1]};

        public:
            EnemyAI(std::string name);
            void perform();

            void BASE_CHASE();
            void BASE_PROTECTION();
            void PICKUP_MODE();
            void PLAYER_CHASE();

            FacingDir moveDirection();
            bool isShooting();
            void resetShooting();
            void MoveTo(sf::Vector2f DisToObj);
            bool inDistance(sf::Vector2f Position, float Distance);
            bool inDistance(sf::Vector2f Position, sf::Vector2f Distance);
            float getDistance(sf::Vector2f distance);
            bool lessDistance(sf::Vector2f first, sf::Vector2f second);
    };
}