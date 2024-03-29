
#include "EnemyShip.hpp"

using namespace entities;

EnemyShip::EnemyShip(std::string name) :
    Ship(name, ObjectTeams::ENEMY){}

void EnemyShip::initialize(){
    this->setTexture(new AnimateTexture(TextureManager::Instance()->getTexturesOf(TextureType::SHIP)));
    this->sprite->scale(5.f, 5.f);
    this->sprite->setColor(sf::Color::Red);
    this->centerOrigin();

    Ship::initialize();
}