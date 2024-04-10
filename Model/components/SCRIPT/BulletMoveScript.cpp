
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
    
    switch(this->facing){
        case FacingDir::UP:
            this->owner->movePosition({0.f, this->deltaTime.asSeconds() * -BULLET_SPEED});
            break;
        case FacingDir::DOWN:
            this->owner->movePosition({0.f, this->deltaTime.asSeconds() * BULLET_SPEED});
            break;
        case FacingDir::LEFT:
            this->owner->movePosition({this->deltaTime.asSeconds() * -BULLET_SPEED, 0.f});
            break;
        case FacingDir::RIGHT:
            this->owner->movePosition({this->deltaTime.asSeconds() * BULLET_SPEED, 0.f});
            break;
    }    
    
    this->elapsedTime += this->deltaTime.asSeconds();

    for(ColliderBase* collision : collider->getCollisions()){
        if(collision->getOwner()->getType() == ObjectType::SHIP){
            Ship* enemy = (Ship*) collision->getOwner();
            if(enemy->getTeam() != ((Bullet*)this->getOwner())->getTeam())
                enemy->damage(BULLET_DAMAGE);
        }
        if(collision->getOwner()->getType() == ObjectType::BASE)
            collider->removeCollision(collision);
    }

    if(this->elapsedTime >= BULLET_MAX_SECONDS || collider->hasColliding()){        
        ObjectPoolManager::Instance()->getObjectPoolByName((this->owner)->getParent()->getName() + "Bullets")->releaseObject(this->owner);
        this->elapsedTime = 0;
    }

    collider->setRadii(this->owner->getSprite()->getGlobalBounds().width / 1.2f, this->owner->getSprite()->getGlobalBounds().height / 1.2f);

    collider->removeAllCollisions();
}

void BulletMoveScript::setFacing(FacingDir direction){
    this->facing = direction;
}