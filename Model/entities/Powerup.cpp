
#include "Powerup.hpp"

using namespace entities;

Powerup::Powerup(std::string name, PowerupType powerupType) :
    Entity(name, ObjectType::POWERUP),
    powerupType(powerupType){}

void Powerup::initialize(){
    this->setTexture(new AnimateTexture(TextureManager::Instance()->getTexturesOf(TextureType::POWERUP)));
    sf::Vector2f scale = {POWERUP_SCALE, POWERUP_SCALE};
    this->sprite->setScale(scale);
    this->centerOrigin();

    if(this->powerupType == PowerupType::SPACE_MINE)
        this->setFrame(0);
    if(this->powerupType == PowerupType::BASE_CHAOS)
        this->setFrame(1);
    if(this->powerupType == PowerupType::BASE_INVINCIBILITY)
        this->setFrame(2);

    this->attachComponent(new PowerupScript(this->getName() + "Script"));

    Entity::initialize();
}

GameObject* Powerup::copy(){
    return new Powerup(this->name, this->powerupType);
}

PowerupType Powerup::getPowerupType(){
    return this->powerupType;
}