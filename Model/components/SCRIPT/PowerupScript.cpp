
#include "PowerupScript.hpp"

using namespace components;

PowerupScript::PowerupScript(std::string name) :
    GenericScript(name){}

void PowerupScript::perform(){

    ColliderBase* collider = (ColliderBase*) this->owner->getComponent(this->owner->getName() + "Collider");

    if(collider == NULL){
        std::cout << "Dependency Missing!" << std::endl;
        return;
    }

    std::vector<ColliderBase*> 
        collisions = collider->getCollisions(),
        shipColliders;

    if(collisions.size() <= 0)
        return;

    for(ColliderBase* checkCollider : collisions){
        if(checkCollider->getOwner()->getType() == ObjectType::SHIP)
            shipColliders.push_back(checkCollider);
    }

    collider->removeAllCollisions();

    if(shipColliders.size() <= 0)
        return;

    for(ColliderBase* shipCollider : shipColliders){
        Ship* ship = (Ship*) shipCollider->getOwner(); 
        switch(((Powerup*) this->owner)->getPowerupType()){
            case PowerupType::BASE_CHAOS:
                this->chaosEffect(ship);
                break;
            case PowerupType::BASE_INVINCIBILITY:
                this->shieldEffect(ship);
                break;
            case PowerupType::SPACE_MINE:
                this->mineEffect(ship);
                break;

        }
    }
    
    ObjectPoolManager::Instance()->getObjectPoolByName(this->getOwner()->getName() + "Pool")->releaseObject(this->owner);
}

void PowerupScript::chaosEffect(Ship* ship){
    
}

void PowerupScript::shieldEffect(Ship* ship){

}

void PowerupScript::mineEffect(Ship* ship){

}