
#include "Base.hpp"

using namespace entities;

Base::Base(std::string name, ObjectTeams team) :
    TeamMember(name, ObjectType::BASE, BASE_MAX_HEALTH, team){}

void Base::initialize(){
    this->setTexture(new AnimateTexture(TextureManager::Instance()->getTexturesOf(TextureType::BASE)));
    this->sprite->scale(5.f, 5.f);
    this->centerOrigin();
    if(this->getTeam() == ObjectTeams::PLAYER)
        ((MatchTrackerScript*) ObjectManager::Instance()->findObjectByName("MatchTracker")->getComponent("MatchTrackerScript"))->incrementPlayerBases();
    if(this->getTeam() == ObjectTeams::ENEMY)
        ((MatchTrackerScript*) ObjectManager::Instance()->findObjectByName("MatchTracker")->getComponent("MatchTrackerScript"))->incrementEnemyBases();

    // Base script

    TeamMember::initialize();
}

void Base::kill(){
    std::cout << "Base died" << std::endl;
    this->iterateFrames();
    if(this->getTeam() == ObjectTeams::PLAYER)
        ((MatchTrackerScript*) ObjectManager::Instance()->findObjectByName("MatchTracker")->getComponent("MatchTrackerScript"))->decrementPlayerBases();
    if(this->getTeam() == ObjectTeams::ENEMY)
        ((MatchTrackerScript*) ObjectManager::Instance()->findObjectByName("MatchTracker")->getComponent("MatchTrackerScript"))->decrementEnemyBases();

}