
#include "Powerup.hpp"

using namespace entities;

Powerup::Powerup(std::string name, PowerupType powerupType) :
    Entity(name, ObjectType::POWERUP),
    powerupType(powerupType){}

void Powerup::initialize(){
    this->setTexture(new AnimateTexture(TextureManager::Instance()->getTexturesOf(TextureType::POWERUP)));
    this->sprite->setScale({10.f, 10.f});
    this->centerOrigin();

    if(this->powerupType == PowerupType::BASE_CHAOS)
        this->iterateFrames();

    this->attachComponent(new PowerupScript(this->getName() + "Script"));

    Entity::initialize();
}

GameObject* Powerup::copy(){
    return new Powerup(this->name, this->powerupType);
}

PowerupType Powerup::getPowerupType(){
    return this->powerupType;
}