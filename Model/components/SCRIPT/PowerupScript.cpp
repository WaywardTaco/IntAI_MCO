
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
        shipColliders = {},
        bulletColliders = {};

    if(collisions.size() <= 0)
        return;

    for(ColliderBase* checkCollider : collisions){
        if(checkCollider->getOwner()->getType() == ObjectType::SHIP)
            shipColliders.push_back(checkCollider);
        if(checkCollider->getOwner()->getType() == ObjectType::BULLET)
            bulletColliders.push_back(checkCollider);
    }

    collider->removeAllCollisions();

    for(ColliderBase* shipCollider : shipColliders){
        Ship* ship = (Ship*) shipCollider->getOwner(); 
        switch(((Powerup*) this->owner)->getPowerupType()){
            case PowerupType::BASE_CHAOS:
                this->chaosEffect(ship);
                ObjectPoolManager::Instance()->getObjectPoolByName(this->getOwner()->getName() + "Pool")->releaseObject(this->owner);
                break;
            case PowerupType::BASE_INVINCIBILITY:
                this->shieldEffect(ship);
                ObjectPoolManager::Instance()->getObjectPoolByName(this->getOwner()->getName() + "Pool")->releaseObject(this->owner);
                break;
            case PowerupType::SPACE_MINE:
                this->mineEffect(ship);
                ObjectPoolManager::Instance()->getObjectPoolByName(this->getOwner()->getName() + "Pool")->releaseObject(this->owner);
                break;

        }
    }
    if(bulletColliders.size() >= 0)
        ObjectPoolManager::Instance()->getObjectPoolByName(this->getOwner()->getName() + "Pool")->releaseObject(this->owner);
    
}

void PowerupScript::chaosEffect(Ship* ship){
    AudioManager::Instance()->playSound(SoundType::CHAOS, 0, 1, 100.f);

    std::vector<GameObject*> bases = ObjectManager::Instance()->getObjects(ObjectType::BASE);
    for(GameObject* object : bases){
        Base* base = (Base*) object;
        if(base->getHealth() > 0.f)
            Utility::setRandomLoc(base);
    }
}

void PowerupScript::shieldEffect(Ship* ship){
    AudioManager::Instance()->playSound(SoundType::SHIELD, 0, 2, 80.f);

    std::vector<GameObject*> bases = ObjectManager::Instance()->getObjects(ObjectType::BASE);
    for(GameObject* object : bases){
        Base* base = (Base*) object;
        if(base->getHealth() > 0.f && base->getTeam() == ship->getTeam()){
            base->startShield();
        }
    }
}

void PowerupScript::mineEffect(Ship* ship){
    if(ship->getHealth() <= MINE_DAMAGE)
        ((MatchTrackerScript*)ObjectManager::Instance()->findObjectByName("MatchTracker")->getComponent("MatchTrackerScript"))->disableNextScore();
    ship->damage(MINE_DAMAGE);
}