
#include "ObjectPoolManager.hpp"

using namespace managers;

void ObjectPoolManager::registerPool(ObjectPool* objectPool){
    this->mapObjectPools[objectPool->getPoolType()] = objectPool;
}

void ObjectPoolManager::clearAllPools(){
    for(std::unordered_map<ObjectType, ObjectPool*>::iterator itr = this->mapObjectPools.begin(); itr != this->mapObjectPools.end(); itr++)
        delete itr->second;
}

ObjectPool* ObjectPoolManager::getObjectPoolByName(std::string name){
    for(std::unordered_map<ObjectType, ObjectPool*>::iterator itr = this->mapObjectPools.begin(); itr != this->mapObjectPools.end(); itr++){
        if(itr->second->getName() == name)
            return itr->second;
    }
    return NULL;
}

ObjectPool* ObjectPoolManager::getObjectPool(ObjectType tag){
    return this->mapObjectPools[tag];
}

/* SINGLETON CODE */
ObjectPoolManager* ObjectPoolManager::SHARED_INSTANCE = NULL;
ObjectPoolManager::ObjectPoolManager(){}
ObjectPoolManager::ObjectPoolManager(const ObjectPoolManager&){}
ObjectPoolManager* ObjectPoolManager::Instance(){
    if(SHARED_INSTANCE == NULL)
        SHARED_INSTANCE = new ObjectPoolManager();

    return SHARED_INSTANCE;
}