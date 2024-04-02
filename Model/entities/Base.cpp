
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

    this->attachComponent(new BaseCaptureScript(this->getName() + "Script"));

    TeamMember::initialize();
}

void Base::kill(){
    std::cout << "Base died" << std::endl;
    this->setFrame(2);
    if(this->getTeam() == ObjectTeams::PLAYER)
        ((MatchTrackerScript*) ObjectManager::Instance()->findObjectByName("MatchTracker")->getComponent("MatchTrackerScript"))->decrementPlayerBases();
    if(this->getTeam() == ObjectTeams::ENEMY)
        ((MatchTrackerScript*) ObjectManager::Instance()->findObjectByName("MatchTracker")->getComponent("MatchTrackerScript"))->decrementEnemyBases();

}

void Base::startShield(){
    if(this->getHealth() <= 0.f)
        return;
    this->setFrame(1);
    BaseCaptureScript* script = (BaseCaptureScript*) this->getComponent(this->getName() + "Script");
    script->startShield();
}
