
#include "Utility.hpp"

using namespace controllers;

int Utility::getRandomNumber(int lowerBound, int upperBound){
    int output = (std::rand() % (upperBound - lowerBound + 1)) + lowerBound;
    return output;
}

void Utility::setRandomLoc(Entity* refEntity){
    GameObject* object = (GameObject*) refEntity;
    ColliderBase* collider = (ColliderBase*) object->getComponent(object->getName() + "Collider");
    do{
        collider->removeAllCollisions();
        object->setPosition({
            Utility::getRandomNumber(
                ((object->getSprite()->getLocalBounds().width * object->getSprite()->getScale().x)), 
                (WINDOW_WIDTH - ((object->getSprite()->getLocalBounds().width * object->getSprite()->getScale().x)))), 
            Utility::getRandomNumber(
                ((object->getSprite()->getLocalBounds().height * object->getSprite()->getScale().y)), 
                (WINDOW_HEIGHT - ((object->getSprite()->getLocalBounds().height * object->getSprite()->getScale().y))))});
        ColliderManager::Instance()->processCollisions();
    } while (collider->hasColliding());
    collider->removeAllCollisions();
}

/* REMOVE INSTANTIATION */
Utility::Utility(){}
Utility::Utility(const Utility&){}