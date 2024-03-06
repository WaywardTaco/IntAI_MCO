
#include "ShipMoveScript.hpp"

using namespace components;

ShipMoveScript::ShipMoveScript(std::string name) : GenericScript(name){}

void ShipMoveScript::perform(){
    MovementInput* input = (MovementInput*) this->getOwner()->getComponent(this->getOwner()->getName() + "MovementInput");

    if(input == NULL){
        std::cout << "[ERROR] Dependency Missing" << std::endl;
        return;
    }

    if(input->getUp())
        this->getOwner()->movePosition({0, -2});
    if(input->getDown())
        this->getOwner()->movePosition({0, 2});
    if(input->getLeft())
        this->getOwner()->movePosition({-2, 0});
    if(input->getRight())
        this->getOwner()->movePosition({2, 0});

}