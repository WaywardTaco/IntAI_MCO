
#include "PlayerShipActions.hpp"

using namespace components;

PlayerShipActions::PlayerShipActions(std::string name) : 
    GenericScript(name){}

void PlayerShipActions::perform(){
    PlayerInput* input = (PlayerInput*) this->getOwner()->getComponent(this->getOwner()->getName() + "PlayerInput");
    Ship* ship = (Ship*) this->getOwner();

    if(input == NULL){
        std::cout << "[ERROR] Dependency Missing" << std::endl;
        return;
    }

    if(input->getUp()){
        ship->movePosition({0, -SHIP_SPEED * this->deltaTime.asSeconds()});
        ship->setFacing(FacingDir::UP);
        ship->getSprite()->setRotation(0.f);
    }
    if(input->getDown()){
        ship->movePosition({0, SHIP_SPEED * this->deltaTime.asSeconds()});
        ship->setFacing(FacingDir::DOWN);
        ship->getSprite()->setRotation(180.f);
    }
    if(input->getLeft()){
        ship->movePosition({-SHIP_SPEED * this->deltaTime.asSeconds(), 0});
        ship->setFacing(FacingDir::LEFT);
        ship->getSprite()->setRotation(-90.f);
    }
    if(input->getRight()){
        ship->movePosition({SHIP_SPEED * this->deltaTime.asSeconds(), 0});
        ship->setFacing(FacingDir::RIGHT);
        ship->getSprite()->setRotation(90.f);
    }
    if(input->getSpace()){
        ObjectPoolManager::Instance()->getObjectPoolByName(ship->getName() + "Bullets")->getObject();
        input->resetSpace();
    }

}