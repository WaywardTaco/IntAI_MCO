
#include "MatchTrackerScript.hpp"

using namespace components;

MatchTrackerScript::MatchTrackerScript(std::string name) : 
    GenericScript(name),
    playerLivingBases(0),
    playerTeamScore(0),
    enemyLivingBases(0),
    enemyTeamScore(0),
    matchTime(0),
    skipNextScore(false){}

void MatchTrackerScript::perform(){
    this->matchTime += this->deltaTime.asSeconds();

    if(this->matchTime >= MATCH_SECONDS || this->playerLivingBases == 0 || this->enemyLivingBases == 0){
        SceneManager::Instance()->loadScene(SceneTag::RESULTS);
        ((ResultsScene*)SceneManager::Instance()->getScene(SceneTag::RESULTS))->passResults(MATCH_SECONDS - this->matchTime, this->playerTeamScore, this->enemyTeamScore, this->playerLivingBases, this->enemyLivingBases);
    }
}

void MatchTrackerScript::incrementPlayerScore(){
    if(!this->skipNextScore)
        this->playerTeamScore++;
    this->skipNextScore = false;
}

void MatchTrackerScript::incrementPlayerBases(){
    this->playerLivingBases++;
}

void MatchTrackerScript::decrementPlayerBases(){
    this->playerLivingBases--;
    if(this->playerLivingBases <= 0)
        this->playerLivingBases = 0;
}

void MatchTrackerScript::incrementEnemyScore(){
    if(!this->skipNextScore)
        this->enemyTeamScore++;
    this->skipNextScore = false;
}

void MatchTrackerScript::incrementEnemyBases(){
    this->enemyLivingBases++;
}

void MatchTrackerScript::decrementEnemyBases(){
    this->enemyLivingBases--;
    if(this->enemyLivingBases <= 0)
        this->enemyLivingBases = 0;
}

void MatchTrackerScript::disableNextScore(){
    this->skipNextScore = true;
}

float MatchTrackerScript::getMatchTime(){
    return this->matchTime;
}

int MatchTrackerScript::getPlayerScore(){
    return this->playerTeamScore;
}

int MatchTrackerScript::getEnemyScore(){
    return this->enemyTeamScore;
}