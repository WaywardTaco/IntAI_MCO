
#include "GenericScript.hpp"

using namespace components;

GenericScript::GenericScript(std::string name) :
    Component(name, ComponentType::SCRIPT), 
    deltaTime(sf::Time::Zero){}
    
void GenericScript::assignDeltaTime(sf::Time deltaTime){
    this->deltaTime = deltaTime;
}
 