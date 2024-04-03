
#include "Ship.hpp"

using namespace entities;

Ship::Ship(std::string name, ObjectTeams team, sf::Vector2f spawnCoords) : 
    TeamMember(name, ObjectType::SHIP, SHIP_MAX_HEALTH, team),
    facing(FacingDir::UP),
    spawnCoords(spawnCoords){}

void Ship::initialize(){
    this->getSprite()->setRotation(0.f);
    this->setPosition(this->spawnCoords);
    TeamMember::initialize();
}

void Ship::kill(){
    this->resetHealth();
    this->setPosition(this->spawnCoords);
}

void Ship::setFacing(FacingDir direction){
    this->facing = direction;
}

FacingDir Ship::getFacing(){
    return this->facing;
}