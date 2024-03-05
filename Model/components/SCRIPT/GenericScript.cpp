
#include "GenericScript.hpp"

using namespace components;

GenericScript::GenericScript(std::string name, GameObject* owner) :
    Component(name, ComponentType::SCRIPT, owner), deltaTime(sf::Time::Zero){}
    
void GenericScript::assignDeltaTime(sf::Time deltaTime){
    this->deltaTime = deltaTime;
}
 