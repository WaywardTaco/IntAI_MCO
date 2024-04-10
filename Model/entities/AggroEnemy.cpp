
#include "AggroEnemy.hpp"

using namespace entities;

AggroEnemy::AggroEnemy(std::string name, sf::Vector2f spawnCoords) 
    : EnemyShip(name, spawnCoords){}

void AggroEnemy::initialize(){
    this->attachComponent(new EnemyAI(this->getName() + "Brain", 10, 40, 100));
    
    AnimateTexture* texture = new AnimateTexture(TextureManager::Instance()->getTexturesOf(TextureType::SHIP));
    texture->iterateFrames();
    texture->iterateFrames();

    this->setTexture(texture);

    EnemyShip::initialize();
}