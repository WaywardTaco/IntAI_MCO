
#include "Entity.hpp"

using namespace entities;

Entity::Entity(std::string name, ObjectType type) : GameObject(name, type){}

void Entity::initialize(){
    GenericRenderer* renderer = new GenericRenderer(this->getName() + "Renderer");
    renderer->assignDrawable(this->sprite);
    this->attachComponent(renderer);

    this->attachComponent(new ColliderBase(this->getName() + "Collider", *(this->sprite)));   
}

GameObject* Entity::copy(){
    return this;
}
