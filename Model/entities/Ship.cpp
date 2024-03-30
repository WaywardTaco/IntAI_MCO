
#include "Ship.hpp"

using namespace entities;

Ship::Ship(std::string name, ObjectTeams team) : 
    TeamMember(name, ObjectType::SHIP, SHIP_MAX_HEALTH, team){}

void Ship::initialize(){
    TeamMember::initialize();
}

void Ship::kill(){
    std::cout << "Ship Died!" << std::endl;
    this->resetHealth();
    Utility::setRandomLoc(this);
}