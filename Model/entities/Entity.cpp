
#include "Entity.hpp"

using namespace entities;

Entity::Entity(std::string name, ObjectType type) : GameObject(name, type){}

GameObject* Entity::copy(){
    return this;
}
