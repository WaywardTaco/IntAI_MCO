
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
        if(!object->isEnabled())
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
    for(GameObject* object : vecObjects)
        delete object;

    vecObjects.clear();
    mapObjects.clear();
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