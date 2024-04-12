
#include "BalanceEnemy.hpp"

using namespace entities;

BalanceEnemy::BalanceEnemy(std::string name, sf::Vector2f spawnCoords) 
    : EnemyShip(name, spawnCoords){}

void BalanceEnemy::initialize(){
    this->attachComponent(new EnemyAI(this->getName() + "Brain", 40, 70, 40));
    
    AnimateTexture* texture = new AnimateTexture(TextureManager::Instance()->getTexturesOf(TextureType::SHIP));
    texture->iterateFrames();

    this->setTexture(texture);

    EnemyShip::initialize();
}