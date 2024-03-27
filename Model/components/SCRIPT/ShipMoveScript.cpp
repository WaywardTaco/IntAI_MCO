
#include "ShipMoveScript.hpp"

using namespace components;

ShipMoveScript::ShipMoveScript(std::string name) : GenericScript(name){}

void ShipMoveScript::perform(){
    MovementInput* input = (MovementInput*) this->getOwner()->getComponent(this->getOwner()->getName() + "MovementInput");

    if(input == NULL){
        std::cout << "[ERROR] Dependency Missing" << std::endl;
        return;
    }

    if(this->owner->getName() == "Ship2"){
        return;
    }

    if(input->getUp()){
        this->getOwner()->movePosition({0, -SHIP_SPEED * this->deltaTime.asSeconds()});
        // input->resetUp();
    }
    if(input->getDown()){
        this->getOwner()->movePosition({0, SHIP_SPEED * this->deltaTime.asSeconds()});
        // input->resetDown();
    }
    if(input->getLeft()){
        this->getOwner()->movePosition({-SHIP_SPEED * this->deltaTime.asSeconds(), 0});
        // input->resetLeft();
    }
    if(input->getRight()){
        this->getOwner()->movePosition({SHIP_SPEED * this->deltaTime.asSeconds(), 0});
        // input->resetRight();
    }
    if(input->getSpace()){
        ObjectPoolManager::Instance()->getObjectPoolByName(this->owner->getName() + "Bullets")->getObject();
        input->resetSpace();
    }

}