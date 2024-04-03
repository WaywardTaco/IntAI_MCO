
#include "EnemyShipActions.hpp"

using namespace components;

EnemyShipActions::EnemyShipActions(std::string name) : 
    GenericScript(name),
    shootingElapsed(0.f){}

void EnemyShipActions::perform(){
    if(this->shootingElapsed > 0.f)
        this->shootingElapsed -= this->deltaTime.asSeconds();

    Ship* ship = (Ship*) this->getOwner();
    EnemyAI* brain = (EnemyAI*) ship->getComponent(ship->getName() + "Brain");

    if(brain == NULL){
        std::cout << "[ERROR] Dependency Missing" << std::endl;
        return;
    }

    if(brain->moveDirection() == FacingDir::UP && ship->getPosition().y > WINDOW_BORDER){
        ship->movePosition({0, -SHIP_SPEED * this->deltaTime.asSeconds()});
        ship->setFacing(FacingDir::UP);
        ship->getSprite()->setRotation(0.f);
    }
    if(brain->moveDirection() == FacingDir::DOWN && ship->getPosition().y < WINDOW_HEIGHT - WINDOW_BORDER){
        ship->movePosition({0, SHIP_SPEED * this->deltaTime.asSeconds()});
        ship->setFacing(FacingDir::DOWN);
        ship->getSprite()->setRotation(180.f);
    }
    if(brain->moveDirection() == FacingDir::LEFT && ship->getPosition().x > WINDOW_BORDER){
        ship->movePosition({-SHIP_SPEED * this->deltaTime.asSeconds(), 0});
        ship->setFacing(FacingDir::LEFT);
        ship->getSprite()->setRotation(-90.f);
    }
    if(brain->moveDirection() == FacingDir::RIGHT && ship->getPosition().x < WINDOW_WIDTH - WINDOW_BORDER){
        ship->movePosition({SHIP_SPEED * this->deltaTime.asSeconds(), 0});
        ship->setFacing(FacingDir::RIGHT);
        ship->getSprite()->setRotation(90.f);
    }
    if(brain->moveDirection() == FacingDir::NONE){}
    if(brain->isShooting() && this->shootingElapsed <= 0.f){
        this->shootingElapsed = 0.2f;
        ObjectPoolManager::Instance()->getObjectPoolByName(ship->getName() + "Bullets")->getObject();
    }

}