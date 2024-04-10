
#include "ObjectManager.hpp"

using namespace managers;
       
void ObjectManager::processEvents(sf::Event event){
    for(GameObject* object : this->vecObjects){
        if(!object->isEnabled())
            continue;

        std::vector<Component*> components = object->getComponents(ComponentType::INPUT);

        for(Component* component : components){
            GenericInput* input = (GenericInput*) component;
            
            input->assignEvent(event);
            input->perform();
        }
    }
}

void ObjectManager::update(sf::Time deltaTime){
    for(GameObject* object : this->vecObjects){
        if(!object->isEnabled() || object->isPaused())
            continue;
        
        std::vector<Component*> components = object->getComponents(ComponentType::SCRIPT);

        for(Component* component : components){
            GenericScript* script = (GenericScript*) component;
            
            script->assignDeltaTime(deltaTime);
            script->perform();
        }   
    }
}

void ObjectManager::draw(sf::RenderWindow* window){
    for(GameObject* object : this->vecObjects){
        if(!object->isEnabled())
            continue;
        
        std::vector<Component*> components = object->getComponents(ComponentType::RENDERER);

        for(Component* component : components){
            GenericRenderer* renderer = (GenericRenderer*) component;
            
            renderer->assignWindow(window);
            renderer->perform();
        }   
    }
}

void ObjectManager::addObject(GameObject* object){
    this->vecObjects.push_back(object);
    this->mapObjects[object->getName()] = object;
    object->initialize();
}

void ObjectManager::deleteObject(GameObject* object){
    int 
        index = -1,
        size = this->vecObjects.size();
    for(int i = 0; i < size; i++){
        if(this->vecObjects[i] != object)
            continue;
        index = i;
        break;
    }
    if(index != -1){
        this->mapObjects.erase(this->vecObjects[index]->getName());
        this->vecObjects.erase(this->vecObjects.begin() + index);
    }
    delete object;
}

GameObject* ObjectManager::findObjectByName(std::string name){
    if(this->mapObjects[name] == NULL){
        std::cout << "Error: Object [" << name << "] not found!" << std::endl;
        return NULL;
    }
    
    return this->mapObjects[name];
}

std::vector<GameObject*> ObjectManager::getObjects(ObjectType type){
    std::vector<GameObject*> output = {};
    
    int length = this->vecObjects.size();
    for(int i = 0; i < length; i++)
        if(this->vecObjects[i]->getType() == type)
            output.push_back(this->vecObjects[i]);

    return output;
}

void ObjectManager::deleteAllObjects(){
    for(GameObject* object : this->vecObjects)
        delete object;

    this->vecObjects.clear();
    this->mapObjects.clear();
}

void ObjectManager::pauseAllObjects(){
    for(GameObject* object : this->vecObjects)
        object->pause();
}

void ObjectManager::unpauseAllObjects(){
    for(GameObject* object : this->vecObjects)
        object->unpause();
}

void ObjectManager::togglePauseAllObjects(){
    for(GameObject* object : this->vecObjects)
        object->togglePause();
}

/* SINGLETON CODE */
ObjectManager* ObjectManager::SHARED_INSTANCE = NULL;
ObjectManager::ObjectManager(){}
ObjectManager::ObjectManager(const ObjectManager&){}
ObjectManager* ObjectManager::Instance(){
    if(SHARED_INSTANCE == NULL)
        SHARED_INSTANCE = new ObjectManager();
    return SHARED_INSTANCE;
};