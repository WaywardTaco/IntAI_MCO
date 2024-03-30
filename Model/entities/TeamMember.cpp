
#include "TeamMember.hpp"

using namespace entities;

TeamMember::TeamMember(std::string name, ObjectType type, float maxHealth, ObjectTeams team) :
    Entity(name, type),
    maxHealth(maxHealth),
    currHealth(maxHealth),
    team(team){}

void TeamMember::initialize(){
    Entity::initialize();
}

GameObject* TeamMember::copy(){
    return this;
}

ObjectTeams TeamMember::getTeam(){
    return this->team;
}

float TeamMember::getHealth(){
    return this->currHealth;
}

float TeamMember::getMaxHealth(){
    return this->maxHealth;
}

void TeamMember::resetHealth(){
    this->currHealth = this->maxHealth;
}

void TeamMember::heal(float amount){
    this->currHealth += amount;
    if(this->currHealth > this->maxHealth);
        this->currHealth = this->maxHealth;
}

void TeamMember::damage(float amount){
    if(this->currHealth <= 0)
        return;
    this->currHealth -= amount;
    if(this->currHealth <= 0){
        this->currHealth = 0;
        this->kill();
    }
}