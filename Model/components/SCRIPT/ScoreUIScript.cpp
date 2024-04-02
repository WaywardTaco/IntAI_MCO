
#include "ScoreUIScript.hpp"

using namespace components;

ScoreUIScript::ScoreUIScript(std::string name) :
    GenericScript(name){};

void ScoreUIScript::perform(){
    MatchTracker* match = (MatchTracker*) ObjectManager::Instance()->findObjectByName("MatchTracker");
    if(match == NULL){
        std::cout << "Dependency Missing!" << std::endl;
        return;
    }

    MatchTrackerScript* tracker = (MatchTrackerScript*) match->getComponent(match->getName() + "Script");
    ScoreUI* owner = (ScoreUI*) this->getOwner();

    if(tracker == NULL || owner == NULL){
        std::cout << "Dependency Missing!" << std::endl;
        return;
    }
    
    if(owner->getTeam() == ObjectTeams::PLAYER)
        owner->setText("Player Score: " + std::to_string(tracker->getPlayerScore()), false);
    if(owner->getTeam() == ObjectTeams::ENEMY)
        owner->setText("Enemy Score: " + std::to_string(tracker->getEnemyScore()), false);
}