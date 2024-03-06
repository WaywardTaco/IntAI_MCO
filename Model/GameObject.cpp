
#include "GameObject.hpp"

using namespace models;

GameObject::GameObject(std::string name, ObjectType type) :
    name(name), 
    type(type),
    sprite(NULL),
    texture(NULL),
    position({0.f, 0.f}), 
    enabled(true){}

void GameObject::attachComponent(Component* component){
    component->attachOwner(this);
    this->components.push_back(component);
}

void GameObject::detachComponent(Component* component){
    int found = -1, length = this->components.size();
    for(int i = 0; i < length; i++){
        if(components[i] == component){
            found = i;
            break;
        }
    }

    if(found != -1){
        components[found]->detachOwner();
        components.erase(this->components.begin() + found);
    }
}

std::vector<Component*> GameObject::getComponents(ComponentType type){
    std::vector<Component*> output = {};

    for(Component* component : this->components){
        if(component->getType() == type)
            output.push_back(component);
    }

    return output;
}

Component* GameObject::getComponent(std::string name){
    for(Component* component : this->components){
        if(component->getName() == name)
            return component;
    }

    return NULL;
}

std::string GameObject::getName(){
    return this->name;
}

ObjectType GameObject::getType(){
    return this->type;
}

sf::Sprite* GameObject::getSprite(){
    this->sprite->setPosition(this->position);
    return this->sprite;
}

void GameObject::setSprite(sf::Sprite* sprite){
    this->sprite = sprite;
}

void GameObject::setTexture(AnimateTexture* texture){
    this->texture = texture;
    if(this->sprite == NULL)
        this->sprite = new sf::Sprite;
    this->sprite->setTexture(*(this->texture->getFrame()));
}

sf::Vector2f GameObject::getPosition(){
    this->position = this->sprite->getPosition();
    return this->position;
}

void GameObject::setPosition(sf::Vector2f position){
    this->position = position;
    this->sprite->setPosition(position);
}

sf::FloatRect GameObject::getBounds(){
    return this->sprite->getGlobalBounds();
}

bool GameObject::isEnabled(){
    return enabled;
}

void GameObject::enable(){
    this->enabled = true;
}

void GameObject::disable(){
    this->enabled = false;
}