
#include "Component.hpp"

using namespace components;

Component::Component(std::string name, ComponentType type, GameObject* owner){
    this->owner = owner;
    this->type = type;
    this->name = this->owner->getName() + name;
}

Component::~Component(){
    this->owner = NULL;
    this->type = ComponentType::NONE;
}

void Component::detachOwner(){
    delete this;
}

GameObject* Component::getOwner(){
    return this->owner;
}

ComponentType Component::getType(){
    return this->type;
}

std::string Component::getName(){
    return this->name;
}
 