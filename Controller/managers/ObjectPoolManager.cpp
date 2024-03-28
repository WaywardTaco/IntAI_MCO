
#include "ObjectPoolManager.hpp"

using namespace managers;

void ObjectPoolManager::registerPool(ObjectPool* objectPool){
    this->mapObjectPools[objectPool->getPoolType()].push_back(objectPool);
}

void ObjectPoolManager::clearAllPools(){
    for(std::unordered_map<ObjectType, std::vector<ObjectPool*>>::iterator itr = this->mapObjectPools.begin(); itr != this->mapObjectPools.end(); itr++){
        for(ObjectPool* pool : itr->second)
            delete pool;
        itr->second.clear();
    }
}

ObjectPool* ObjectPoolManager::getObjectPoolByName(std::string name){
    for(std::unordered_map<ObjectType, std::vector<ObjectPool*>>::iterator itr = this->mapObjectPools.begin(); itr != this->mapObjectPools.end(); itr++){
        for(ObjectPool* pool : itr->second){
            if(pool->getName() == name)
                return pool;
        }
    }
    return NULL;
}

ObjectPool* ObjectPoolManager::getObjectPool(ObjectType tag){
    return this->mapObjectPools[tag].front();
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