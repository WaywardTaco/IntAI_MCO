
#pragma once

#include "Scene.hpp"
#include "../uiElements/Background.hpp"
#include "../uiElements/TextElement.hpp"
#include "../components/INPUT/ResultsPromptInput.hpp"
#include "../components/SCRIPT/ResultsPromptScript.hpp"
#include "../enums/ObjectTeams.hpp"
#include "../../Config/BalanceSettings.hpp"
#include "../../Config/GameSettings.hpp"

namespace scenes {
    using namespace uiElements;
    using namespace components;
    class ResultsScene : public Scene {
        private:
            sf::Font uiFont;
            float timeLeft;
            int 
                playerKills,
                enemyKills,
                playerBasesLeft,
                enemyBasesDestroyed,
                playerScore;
            ObjectTeams winner;

        public:
            ResultsScene();
            
            void onLoadResources();
            void onLoadObjects();
            void passResults(float timeLeft, int playerKills, int enemyKills, int playerBases, int enemyBases);
    };
}