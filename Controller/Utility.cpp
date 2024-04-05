
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

        int
        xlb = (WINDOW_BORDER + (object->getSprite()->getLocalBounds().width * object->getSprite()->getScale().x)),
        xup = ((WINDOW_WIDTH - WINDOW_BORDER) - ((object->getSprite()->getLocalBounds().width * object->getSprite()->getScale().x))),
        ylb = (WINDOW_BORDER + (object->getSprite()->getLocalBounds().height * object->getSprite()->getScale().y)),
        yup = ((WINDOW_HEIGHT - WINDOW_BORDER) - ((object->getSprite()->getLocalBounds().height * object->getSprite()->getScale().y)));

        float
        xPos = Utility::getRandomNumber(xlb, xup),
        yPos = Utility::getRandomNumber(ylb, yup);

        object->setPosition({xPos, yPos});
        ColliderManager::Instance()->processCollisions();

    } while (collider->hasColliding());
    collider->removeAllCollisions();
}

/* REMOVE INSTANTIATION */
Utility::Utility(){}
Utility::Utility(const Utility&){}