
#include "PlayerShipActions.hpp"

using namespace components;

PlayerShipActions::PlayerShipActions(std::string name) : 
    GenericScript(name){}

void PlayerShipActions::perform(){
    PlayerInput* input = (PlayerInput*) this->getOwner()->getComponent(this->getOwner()->getName() + "PlayerInput");

    if(input == NULL){
        std::cout << "[ERROR] Dependency Missing" << std::endl;
        return;
    }

    if(input->getUp()){
        this->getOwner()->movePosition({0, -SHIP_SPEED * this->deltaTime.asSeconds()});
    }
    if(input->getDown()){
        this->getOwner()->movePosition({0, SHIP_SPEED * this->deltaTime.asSeconds()});
    }
    if(input->getLeft()){
        this->getOwner()->movePosition({-SHIP_SPEED * this->deltaTime.asSeconds(), 0});
    }
    if(input->getRight()){
        this->getOwner()->movePosition({SHIP_SPEED * this->deltaTime.asSeconds(), 0});
    }
    if(input->getSpace()){
        ObjectPoolManager::Instance()->getObjectPoolByName(this->owner->getName() + "Bullets")->getObject();
        input->resetSpace();
    }

}