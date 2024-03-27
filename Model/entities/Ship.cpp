
#include "Ship.hpp"

using namespace entities;

Ship::Ship(std::string name) : Entity(name, ObjectType::SHIP){}

void Ship::initialize(){
    this->setTexture(new AnimateTexture(TextureManager::Instance()->getTexturesOf(TextureType::TANK_ROLL_RIGHT)));
    this->sprite->scale(0.5f, 0.5f);
    this->sprite->setOrigin(this->sprite->getTexture()->getSize().x/2.f, this->sprite->getTexture()->getSize().y/2.f);

    GenericRenderer* renderer = new GenericRenderer(this->getName() + "Renderer");
    renderer->assignDrawable(this->sprite);
    this->attachComponent(renderer);

    this->attachComponent(new PlayerShipMovementInput(this->getName() + "MovementInput"));    
    this->attachComponent(new ShipMoveScript(this->getName() + "MovementScript"));    

    this->attachComponent(new ColliderBase(this->getName() + "Collider", this->sprite->getLocalBounds().width / 2.f, this->sprite->getLocalBounds().height / 2.f));
}