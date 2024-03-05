
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

}

GameObject* ObjectManager::findObjectByName(std::string name){

}

void ObjectManager::deleteAllObjects(){

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