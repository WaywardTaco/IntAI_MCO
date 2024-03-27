
#include "Powerup.hpp"

using namespace entities;

Powerup::Powerup(std::string name, PowerupType type) :
    Entity(name, ObjectType::POWERUP),
    type(type){}

void Powerup::initialize(){
    this->setTexture(new AnimateTexture);
}