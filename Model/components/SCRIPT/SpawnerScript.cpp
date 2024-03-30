
#include "SpawnerScript.hpp"

using namespace components;

SpawnerScript::SpawnerScript(std::string name) :
    GenericScript(name){}

void SpawnerScript::perform(){
    ObjectPool* spawnPool = ((Spawner*)this->getOwner())->getPool();

    if(spawnPool == NULL){
        std::cout << "Dependency Missing" << std::endl;
        return;
    }

    if(spawnPool->isEmpty())
        return;

    this->elapsedTime += this->deltaTime.asSeconds();

    if(elapsedTime < SPAWN_SECONDS)
        return;

    this->elapsedTime = 0.f;

    Utility::setRandomLoc((Entity*) spawnPool->getObject());
}