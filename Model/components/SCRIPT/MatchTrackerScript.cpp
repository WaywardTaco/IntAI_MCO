
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
        std::cout << "Game Over!" << std::endl;
        if(this->playerLivingBases <= 0)
            std::cout << "Enemy Wins!" << std::endl;
        else if(this->enemyLivingBases <= 0)
            std::cout << "Player Wins!" << std::endl;
        else if(this->playerLivingBases > this->enemyLivingBases)
            std::cout << "Player Wins!" << std::endl;
        else if(this->playerLivingBases < this->enemyLivingBases)
            std::cout << "Enemy Wins!" << std::endl;
        else if(this->playerTeamScore > this->enemyTeamScore)
            std::cout << "Player Wins!" << std::endl;
        else if(this->playerTeamScore > this->enemyTeamScore)
            std::cout << "Enemy Wins!" << std::endl;
        else {
            std::cout << "It's a tie!" << std::endl;
        }
        SceneManager::Instance()->loadScene(SceneTag::RESULTS);
        
        
        // SceneManager::Instance()->getScene(SceneTag::RESULTS);
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