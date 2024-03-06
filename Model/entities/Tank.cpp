
#include "Tank.hpp"

using namespace entities;

Tank::Tank(std::string name) : Entity(name, ObjectType::TANK){}

void Tank::initialize(){
    this->setTexture(new AnimateTexture(TextureManager::Instance()->getTexturesOf(TextureType::TANK_ROLL_RIGHT)));
    this->sprite->scale(2.5, 2.5);

    GenericRenderer* renderer = new GenericRenderer(this->getName() + "Renderer");
    renderer->assignDrawable(this->sprite);
    this->attachComponent(renderer);

    this->attachComponent(new PlayerShipMovementInput(this->getName() + "MovementInput"));    
    this->attachComponent(new ShipMoveScript(this->getName() + "MovementScript"));    
}