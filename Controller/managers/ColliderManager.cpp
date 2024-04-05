
#include "ColliderManager.hpp"

using namespace managers;

void ColliderManager::processCollisions(){
    for(ColliderBase* currentCollider : this->colliders){
        currentCollider->removeAllCollisions();

        if(!currentCollider->getOwner()->isEnabled())
            continue;

        for(ColliderBase* checkCollider : this->colliders){
            if(!checkCollider->getOwner()->isEnabled())
                continue;

            if(checkCollider == currentCollider)
                continue;

            float
                xDistSqrd = std::pow(currentCollider->getPosition().x - checkCollider->getPosition().x, 2),
                yDistSqrd = std::pow(currentCollider->getPosition().y - checkCollider->getPosition().y, 2);

            if(xDistSqrd > std::pow(currentCollider->getXRadius() + checkCollider->getXRadius(), 2))
                continue;

            if(yDistSqrd > std::pow(currentCollider->getYRadius() + checkCollider->getYRadius(), 2))
                continue;
            
            currentCollider->addCollision(checkCollider);
        }
    }
}

void ColliderManager::registerCollider(ColliderBase* collider){
    this->colliders.push_back(collider);
}

void ColliderManager::clearAllColliders(){
    this->colliders.clear();
}

/* SINGLETON CODE */
ColliderManager* ColliderManager::SHARED_INSTANCE = NULL;
ColliderManager::ColliderManager(){}
ColliderManager::ColliderManager(const ColliderManager&){}
ColliderManager* ColliderManager::Instance(){
    if(SHARED_INSTANCE == NULL)
        SHARED_INSTANCE = new ColliderManager();

    return SHARED_INSTANCE;
}