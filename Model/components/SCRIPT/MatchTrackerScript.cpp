
#include "MatchTrackerScript.hpp"

using namespace components;

MatchTrackerScript::MatchTrackerScript(std::string name) : 
    GenericScript(name),
    playerLivingBases(0),
    playerTeamScore(0),
    enemyLivingBases(0),
    enemyTeamScore(0){}

void MatchTrackerScript::perform(){
}

void MatchTrackerScript::incrementPlayerScore(){
    this->playerTeamScore++;
    if(this->playerTeamScore >= SCORE_GOAL)
        std::cout << "Player Reached Max Score!" << std::endl;
}

void MatchTrackerScript::incrementPlayerBases(){
    this->playerLivingBases++;
}

void MatchTrackerScript::decrementPlayerBases(){
    this->playerLivingBases--;
    if(this->playerLivingBases <= 0)
        this->playerLivingBases = 0;
    if(this->playerLivingBases == 0)
        std::cout << "All Player Bases Destroyed!" << std::endl;
}

void MatchTrackerScript::incrementEnemyScore(){
    this->enemyTeamScore++;
    if(this->enemyTeamScore >= SCORE_GOAL)
        std::cout << "Enemy Reached Max Score!" << std::endl;
}

void MatchTrackerScript::incrementEnemyBases(){
    this->enemyLivingBases++;
}

void MatchTrackerScript::decrementEnemyBases(){
    this->enemyLivingBases--;
    if(this->enemyLivingBases <= 0)
        this->enemyLivingBases = 0;
    if(this->enemyLivingBases == 0)
        std::cout << "All Enemy Bases Destroyed!" << std::endl;
}