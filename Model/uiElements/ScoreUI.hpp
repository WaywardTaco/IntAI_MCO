
#pragma once

#include "TextElement.hpp"
#include "../enums/ObjectTeams.hpp"
#include "../components/SCRIPT/ScoreUIScript.hpp"
#include "../../Config/GameSettings.hpp"

namespace uiElements {
    using namespace components;
    class ScoreUI : public TextElement {
        private:
            ObjectTeams team;
        public:
            ScoreUI(std::string name, ObjectTeams team, sf::Font* font);
            void initialize();
            ObjectTeams getTeam();
    };
}