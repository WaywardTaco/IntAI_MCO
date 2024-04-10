
#include "SpawnerScript.hpp"

using namespace components;

SpawnerScript::SpawnerScript(std::string name) :
    GenericScript(name), elapsedTime(0.f){}

void SpawnerScript::perform(){
    this->elapsedTime += this->deltaTime.asSeconds();
    if(this->elapsedTime < SPAWN_SECONDS)
        return;

    ObjectPool* spawnPool = NULL;

    switch(Utility::getRandomNumber(0, 2)){
        case 1:
            spawnPool = ((Spawner*)this->getOwner())->getMinePool();
            break;
        case 2:
            spawnPool = ((Spawner*)this->getOwner())->getChaosPool();
            break;
        default:
            spawnPool = ((Spawner*)this->getOwner())->getShieldPool();
            break;
    }

    if(spawnPool == NULL)
        return;

    if(spawnPool->isEmpty())
        return;
    
    if(this->elapsedTime >= SPAWN_SECONDS){
        this->elapsedTime = 0.f;
        Utility::setRandomLoc((Entity*) spawnPool->getObject());
    }
}