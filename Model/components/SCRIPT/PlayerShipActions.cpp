
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

    if(input->getUp() && ship->getPosition().y > WINDOW_BORDER){
        ship->movePosition({0, -SHIP_SPEED * this->deltaTime.asSeconds()});
        ship->setFacing(FacingDir::UP);
        ship->getSprite()->setRotation(0.f);
    }
    if(input->getDown() && ship->getPosition().y < WINDOW_HEIGHT - WINDOW_BORDER){
        ship->movePosition({0, SHIP_SPEED * this->deltaTime.asSeconds()});
        ship->setFacing(FacingDir::DOWN);
        ship->getSprite()->setRotation(180.f);
    }
    if(input->getLeft() && ship->getPosition().x > WINDOW_BORDER){
        ship->movePosition({-SHIP_SPEED * this->deltaTime.asSeconds(), 0});
        ship->setFacing(FacingDir::LEFT);
        ship->getSprite()->setRotation(-90.f);
    }
    if(input->getRight() && ship->getPosition().x < WINDOW_WIDTH - WINDOW_BORDER){
        ship->movePosition({SHIP_SPEED * this->deltaTime.asSeconds(), 0});
        ship->setFacing(FacingDir::RIGHT);
        ship->getSprite()->setRotation(90.f);
    }
    if(input->getSpace()){
        ObjectPoolManager::Instance()->getObjectPoolByName(ship->getName() + "Bullets")->getObject();
        input->resetSpace();
    }

    ColliderBase* collider = (ColliderBase*) ship->getComponent(ship->getName() + "Collider");
    collider->setRadii(ship->getSprite()->getGlobalBounds().width / 3.f, ship->getSprite()->getGlobalBounds().height / 3.f);
}