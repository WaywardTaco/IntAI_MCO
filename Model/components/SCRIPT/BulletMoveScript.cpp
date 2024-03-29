
#include "BulletMoveScript.hpp"

using namespace components;

BulletMoveScript::BulletMoveScript(std::string name) :
    GenericScript(name),
    elapsedTime(0.f){}

void BulletMoveScript::perform(){
    ColliderBase* collider = (ColliderBase*) this->getOwner()->getComponent(this->getOwner()->getName() + "Collider");
    if(collider == NULL)
        std::cout << "Dependency Missing!" << std::endl;

    collider->removeCollision((ColliderBase*) this->getOwner()->getParent()->getComponent(this->getOwner()->getParent()->getName() + "Collider"));

    this->owner->movePosition({this->deltaTime.asSeconds() * BULLET_SPEED, 0.f});
    this->elapsedTime += this->deltaTime.asSeconds();
    if(this->elapsedTime >= BULLET_MAX_SECONDS || collider->hasColliding()){
        for(ColliderBase* collision : collider->getCollisions()){
            if(collision->getOwner()->getType() == ObjectType::BASE){
                Base* base = (Base*) collision->getOwner();
                if(base->getTeam() != ((Bullet*)this->getOwner())->getTeam())
                    base->damage(BULLET_DAMAGE);
            }
            if(collision->getOwner()->getType() == ObjectType::SHIP){
                Ship* enemy = (Ship*) collision->getOwner();
                if(enemy->getTeam() != ((Bullet*)this->getOwner())->getTeam())
                    enemy->damage(BULLET_DAMAGE);
            }
            collider->removeCollision(collision);
        }
        
        ObjectPoolManager::Instance()->getObjectPoolByName((this->owner)->getParent()->getName() + "Bullets")->releaseObject(this->owner);
        this->elapsedTime = 0;
    }
}