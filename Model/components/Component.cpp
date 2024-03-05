
#include "Component.hpp"

using namespace components;

Component::Component(std::string name, ComponentType type){
    this->type = type;
    this->name = name;
}

Component::~Component(){
    this->owner = NULL;
    this->type = ComponentType::NONE;
}

void Component::attachOwner(GameObject* owner){
    this->owner = owner;
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
 