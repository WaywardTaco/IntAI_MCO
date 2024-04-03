
#include "ScoreUI.hpp"

using namespace uiElements;

ScoreUI::ScoreUI(std::string name, ObjectTeams team, sf::Font* font) :
    TextElement(name, "Kills: 0", font, SCORE_FONT_SIZE, ObjectType::SCORE_UI),
    team(team){};

void ScoreUI::initialize(){
    this->attachComponent(new ScoreUIScript(this->getName() + "Script"));
    TextElement::initialize();
}

ObjectTeams ScoreUI::getTeam(){
    return this->team;
}