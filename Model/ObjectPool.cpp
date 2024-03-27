
#include "ObjectPool.hpp"

using namespace models;

ObjectPool::ObjectPool(std::string name, int poolSize, GameObject* refObject) :
    name(name), poolSize(poolSize), refObject(refObject), availableObjects({}), usedObjects({}){}

ObjectPool::~ObjectPool(){
    for(GameObject* object : this->usedObjects)
        this->releaseObject(object);

    for(GameObject* object : this->availableObjects)
        ObjectManager::Instance()->deleteObject(object);

    this->usedObjects.clear();
    this->availableObjects.clear();
}

void ObjectPool::initialize(){
    for(int i = 0; i < this->poolSize; i++){
        GameObject* copy = this->refObject->copy();
        copy->disable();
        ObjectManager::Instance()->addObject(copy);
        this->availableObjects.push_back(copy);
    }
}

GameObject* ObjectPool::getObject(){
    if(this->availableObjects.size() < 1)
        return NULL;

    GameObject* object = this->availableObjects.back();
    this->usedObjects.push_back(object);
    this->availableObjects.pop_back();
    object->enable();
    object->onActivate();
    return object;
}

std::vector<GameObject*> ObjectPool::getObjects(int count){
    if(this->availableObjects.size() < count)
        return {};
    
    std::vector<GameObject*> output;
    for(int i = 0; i < count; i++){
        GameObject* object = this->availableObjects.back();
        this->availableObjects.pop_back();
        this->usedObjects.push_back(object);
        object->enable();
        object->onActivate();
        output.push_back(object);
    }
    return output;
}

void ObjectPool::releaseObject(GameObject* object){
    int 
        index = -1,
        size = this->usedObjects.size();
    for(int i = 0; i < size; i++){
        if(this->usedObjects[i] == object){
            index = i;
            break;
        }
    }
    if(index == -1)
        return;

    object->onRelease();
    object->disable();
    this->availableObjects.push_back(object);
    this->usedObjects.erase(this->usedObjects.begin() + index);
}

void ObjectPool::releaseObjects(std::vector<GameObject*> vecObjects){
    for(GameObject* object : vecObjects){
        int 
            index = -1,
            size = this->usedObjects.size();
        for(int i = 0; i < size; i++){
            if(this->usedObjects[i] == object){
                index = i;
                break;
            }
        }
        if(index == -1)
            continue;
        this->usedObjects[index]->onRelease();
        this->usedObjects[index]->disable();
        this->availableObjects.push_back(this->usedObjects[index]);
        this->usedObjects.erase(this->usedObjects.begin() + index);
    }
}

ObjectType ObjectPool::getPoolType(){
    return this->poolType;
}

std::string ObjectPool::getName(){
    return this->name;
}