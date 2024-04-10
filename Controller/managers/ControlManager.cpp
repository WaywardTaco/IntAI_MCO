#include "ControlManager.hpp"

using namespace managers;

void ControlManager::setControlScheme(int count){
    std::cout << "Test" << std::endl;
    if(count % 2 == 0){
        this->up = sf::Keyboard::W;
        this->down = sf::Keyboard::S;
        this->left = sf::Keyboard::A;
        this->right = sf::Keyboard::D;
    }

    else{
        this->up = sf::Keyboard::Up;
        this->down = sf::Keyboard::Down;
        this->left = sf::Keyboard::Left;
        this->right = sf::Keyboard::Right;
    }
}

sf::Keyboard::Key ControlManager::getUp(){
    return this->up;
}

sf::Keyboard::Key ControlManager::getDown(){
    return this->down;
}

sf::Keyboard::Key ControlManager::getLeft(){
    return this->left;
}

sf::Keyboard::Key ControlManager::getRight(){
    return this->right;
}


ControlManager* ControlManager::P_SHARED_INSTANCE = NULL;
ControlManager::ControlManager() : up(sf::Keyboard::W), down(sf::Keyboard::S), 
                                    left(sf::Keyboard::A), right(sf::Keyboard::D){}
ControlManager::ControlManager(const ControlManager&){}
ControlManager* ControlManager::getInstance(){
    if(P_SHARED_INSTANCE == NULL)
        P_SHARED_INSTANCE = new(ControlManager);
    return P_SHARED_INSTANCE;
}