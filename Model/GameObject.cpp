
#include "GameObject.hpp"

using namespace models;

GameObject::GameObject(std::string name, ObjectType type) :
    parent(NULL),
    children({}),
    name(name), 
    type(type),
    sprite(NULL),
    texture(NULL),
    position({0.f, 0.f}), 
    enabled(true),
    components({}){}

GameObject::~GameObject(){
    if(this->sprite != NULL)
        delete this->sprite;
    if(this->texture != NULL)
        delete this->texture;
    for(Component* component : this->components){
        component->detachOwner();
    }
    this->components.clear();
    this->children.clear();
}

void GameObject::onActivate(){}

void GameObject::onRelease(){}

GameObject* GameObject::copy(){
    return this;
}

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

void GameObject::attachParent(GameObject* parent){
    this->parent = parent;
    this->parent->children.push_back(this);
}

void GameObject::detachParent(){
    if(this->parent == NULL)
        return;
    
    int 
        index = -1, 
        size = this->parent->children.size();
    for(int i = 0; i < size; i++){
        if(this->parent->children[i] == this){
            index = i;
            break;
        }
    }

    if(index != -1)
        this->parent->children.erase(this->parent->children.begin() + index);

    this->parent = NULL;
}

GameObject* GameObject::getParent(){
    return this->parent;
}

void GameObject::centerOrigin(){
    if(this->sprite == NULL)
        return;

    this->sprite->setOrigin(this->sprite->getTexture()->getSize().x/2.f, this->sprite->getTexture()->getSize().y/2.f);
}

void GameObject::iterateFrames(){
    this->texture->iterateFrames();
    this->sprite->setTexture(*this->texture->getFrame());
}

void GameObject::setFrame(int frame){
    this->frame = frame;
    this->texture->setFrame(frame);
    this->sprite->setTexture(*this->texture->getFrame(), true);
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

float GameObject::getRotation(){
    return this->sprite->getRotation();
}

void GameObject::setPosition(sf::Vector2f position){
    this->position = position;
    this->sprite->setPosition(position);
}
void GameObject::movePosition(sf::Vector2f move){
    this->setPosition({this->position.x + move.x, this->position.y + move.y});
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

int GameObject::getFrame() {
    return this->frame;
}