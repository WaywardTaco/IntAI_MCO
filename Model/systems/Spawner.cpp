
#include "Spawner.hpp"

using namespace systems;

Spawner::Spawner(std::string name, ObjectPool* minePool, ObjectPool* chaosPool, ObjectPool* shieldPool) :
    System(name, ObjectType::SPAWNER),
    minePool(minePool),
    chaosPool(chaosPool),
    shieldPool(shieldPool){}

void Spawner::initialize(){
    if(this->minePool != NULL){
        ObjectPoolManager::Instance()->registerPool(this->minePool);
        this->minePool->initialize();
    }
    if(this->chaosPool != NULL){
        ObjectPoolManager::Instance()->registerPool(this->chaosPool);
        this->chaosPool->initialize();
    }
    if(this->shieldPool != NULL){
        ObjectPoolManager::Instance()->registerPool(this->shieldPool);
        this->shieldPool->initialize();
    }
    
    this->attachComponent(new SpawnerScript(this->getName() + "Script"));
}

ObjectPool* Spawner::getMinePool(){
    return this->minePool;
}

ObjectPool* Spawner::getChaosPool(){
    return this->chaosPool;
}

ObjectPool* Spawner::getShieldPool(){
    return this->shieldPool;
}