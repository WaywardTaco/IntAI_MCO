
#pragma once

#include "GenericScript.hpp"
#include "../../../Config/BalanceSettings.hpp"

namespace components {
    class MatchTrackerScript : public GenericScript {
        private:
            int
                playerTeamScore,
                playerLivingBases,
                enemyTeamScore,
                enemyLivingBases;
            float matchTime;
            bool skipNextScore;
        public:
            MatchTrackerScript(std::string name);
            void perform();

            void incrementPlayerScore();
            void incrementPlayerBases();
            void decrementPlayerBases();
            void incrementEnemyScore();
            void incrementEnemyBases();
            void decrementEnemyBases();
            void disableNextScore();
    };
}