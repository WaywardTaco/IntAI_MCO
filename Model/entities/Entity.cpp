
#include "Entity.hpp"

using namespace entities;

Entity::Entity() : GameObject("Object", ObjectType::TANK){}

void Entity::initialize() {
    this->setTexture(new AnimateTexture(TextureManager::Instance()->getTexturesOf(TextureType::TANK_ROLL_RIGHT)));  
    this->sprite->scale(2, 2);

    GenericRenderer* renderer = new GenericRenderer(this->getName() + "Renderer");
    renderer->assignDrawable(this->sprite);
    this->attachComponent(renderer);
}