
#include "EnemyShip.hpp"

using namespace entities;

EnemyShip::EnemyShip(std::string name, sf::Vector2f spawnCoords) :
    Ship(name, ObjectTeams::ENEMY, spawnCoords){}

void EnemyShip::initialize(){
    this->sprite->scale(5.f, 5.f);
    this->sprite->setColor(sf::Color::Red);
    this->centerOrigin();

    this->attachComponent(new EnemyShipActions(this->getName() + "Script"));

    ObjectPool* bullets = new ObjectPool(this->getName() + "Bullets", MAX_ENEMY_BULLETS, new Bullet("Bullet", this));
    bullets->initialize();
    ObjectPoolManager::Instance()->registerPool(bullets);

    Ship::initialize();
}

void EnemyShip::kill(){
    Ship::kill();
    ((MatchTrackerScript*) ObjectManager::Instance()->findObjectByName("MatchTracker")->getComponent("MatchTrackerScript"))->incrementPlayerScore();
}