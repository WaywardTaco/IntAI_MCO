
#pragma once

#include "BaseCaptureScript.hpp"

using namespace components;

BaseCaptureScript::BaseCaptureScript(std::string name) : 
    GenericScript(name),
    shieldTime(0.f),
    captureTime(0.f),
    shielded(false){}

void BaseCaptureScript::perform(){

    if(((Base*)this->getOwner())->getHealth() <= 0.f)
        return;

    if(this->shielded){
        this->shieldTime += this->deltaTime.asSeconds();
    }
    if(this->shieldTime >= SHIELD_TIMELIMIT){
        if(((Base*)this->getOwner())->getHealth() > 0.f)
            this->getOwner()->setFrame(0);
        if(((Base*)this->getOwner())->getHealth() <= 0.f)
            this->getOwner()->setFrame(1);
        this->shieldTime = 0.f;
        this->shielded = false;
    }

    ColliderBase* collider = (ColliderBase*) this->getOwner()->getComponent(this->getOwner()->getName() + "Collider");
    Ship* enemyShip = NULL;

    for(ColliderBase* checkCollider : collider->getCollisions()){
        if(checkCollider->getOwner()->getType() == ObjectType::SHIP){
            if(((Ship*)checkCollider->getOwner())->getTeam() != ((Base*)this->getOwner())->getTeam()){
                enemyShip = (Ship*) checkCollider->getOwner();
                break;
            }
        }
    }

    if(!collider->hasColliding() || enemyShip == NULL || this->shielded){
        if(this->captureTime > 0.f)
            this->captureTime -= BASE_CAPTURE_DEGRADE_RATE * this->deltaTime.asSeconds();
        if(this->captureTime < 0.f)
            this->captureTime = 0.f;
        collider->removeAllCollisions();
        return;
    }

    collider->removeAllCollisions();

    this->captureTime += BASE_CAPTURE_RATE * this->deltaTime.asSeconds();
    if(this->captureTime >= BASE_CAPTURE_TIME)
        ((Base*)this->getOwner())->damage(BASE_MAX_HEALTH);
}

void BaseCaptureScript::startShield(){
    this->shielded = true;
}