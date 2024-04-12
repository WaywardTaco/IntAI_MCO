
#include "DefenseEnemy.hpp"

using namespace entities;

DefenseEnemy::DefenseEnemy(std::string name, sf::Vector2f spawnCoords) 
    : EnemyShip(name, spawnCoords){}

void DefenseEnemy::initialize(){
    this->attachComponent(new EnemyAI(this->getName() + "Brain", 80, 50, 20));
    
    AnimateTexture* texture = new AnimateTexture(TextureManager::Instance()->getTexturesOf(TextureType::SHIP));
    texture->iterateFrames();
    texture->iterateFrames();
    texture->iterateFrames();

    this->setTexture(texture);

    EnemyShip::initialize();
}