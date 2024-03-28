
#include "PlayerShip.hpp"

using namespace entities;

PlayerShip::PlayerShip(std::string name) : Entity(name, ObjectType::SHIP){}

void PlayerShip::initialize(){
    this->setTexture(new AnimateTexture(TextureManager::Instance()->getTexturesOf(TextureType::SHIP)));
    this->sprite->scale(5.f, 5.f);
    this->centerOrigin();

    this->attachComponent(new PlayerInput(this->getName() + "PlayerInput"));    
    this->attachComponent(new PlayerShipActions(this->getName() + "ShipActions"));    

    Entity::initialize();

    ObjectPool* bullets = new ObjectPool(this->getName() + "Bullets", MAX_PLAYER_BULLETS, new Bullet("Bullet", this));
    bullets->initialize();
    ObjectPoolManager::Instance()->registerPool(bullets);
    
}