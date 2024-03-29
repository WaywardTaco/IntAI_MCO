
#include "Spawner.hpp"

using namespace systems;

Spawner::Spawner(std::string name, ObjectPool* spawnPool) :
    System(name, ObjectType::SPAWNER),
    spawnPool(spawnPool){}

void Spawner::initialize(){
    ObjectPoolManager::Instance()->registerPool(spawnPool);
    this->spawnPool->initialize();
    
    this->attachComponent(new SpawnerScript(this->getName() + "Script"));
}

ObjectPool* Spawner::getPool(){
    return this->spawnPool;
}