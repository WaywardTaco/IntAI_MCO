
#include "ColliderBase.hpp"

using namespace components;

ColliderBase::ColliderBase(std::string name, sf::Sprite referenceSprite) :
    ColliderBase(name, 
    referenceSprite.getLocalBounds().width / 2.f * referenceSprite.getScale().x, 
    referenceSprite.getLocalBounds().height / 2.f * referenceSprite.getScale().y){}

ColliderBase::ColliderBase(std::string name, float xRadius, float yRadius) :
    Component(name, ComponentType::COLLIDER),
    xRadius(xRadius),
    yRadius(yRadius),
    hasCollisions(false),
    collisions({})
{
    ColliderManager::Instance()->registerCollider(this);
}

void ColliderBase::perform(){}

void ColliderBase::addCollision(ColliderBase* collider){
    hasCollisions = true;
    this->collisions.push_back(collider);
}

void ColliderBase::removeCollision(ColliderBase* collider){
    if(!this->hasCollisions)
        return;

    int
        index = -1,
        size = this->collisions.size();
    for(int i = 0; i < size; i++){
        if(collider == this->collisions[i]){
            index = i;
            break;
        }
    }

    if(index != -1)
        this->collisions.erase(this->collisions.begin() + index);
        
    if(this->collisions.size() <= 0)
        this->hasCollisions = false;
}

void ColliderBase::removeAllCollisions(){
    this->collisions.clear();
    this->hasCollisions = false;
}

float ColliderBase::getXRadius(){
    return this->xRadius;
}

float ColliderBase::getYRadius(){
    return this->yRadius;
}

sf::Vector2f ColliderBase::getPosition(){
    return this->getOwner()->getPosition();
}

std::vector<ColliderBase*> ColliderBase::getCollisions(){
    return this->collisions;
}

bool ColliderBase::hasColliding(){
    return this->hasCollisions;
}