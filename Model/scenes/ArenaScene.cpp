
#include "ArenaScene.hpp"

using namespace scenes;

ArenaScene::ArenaScene() 
    : Scene(SceneTag::ARENA){}

void ArenaScene::onLoadResources(){
    TextureManager::Instance()->loadTexture(TextureType::TANK_ROLL_RIGHT, "Frame1");
    TextureManager::Instance()->loadTexture(TextureType::TANK_ROLL_RIGHT, "Frame2");
    TextureManager::Instance()->loadTexture(TextureType::TANK_ROLL_RIGHT, "Frame3");
    TextureManager::Instance()->loadTexture(TextureType::TANK_ROLL_RIGHT, "Frame4");
    TextureManager::Instance()->loadTexture(TextureType::BULLET, "Frame1");
    TextureManager::Instance()->loadTexture(TextureType::BACKGROUND, "MainMenu");
}

void ArenaScene::onLoadObjects(){
    Background* background = new Background("Background");
    background->getSprite()->setScale(2.f, 2.f);

    ObjectManager::Instance()->addObject(background);
    
    Ship* ship1 = new Ship("Ship1");
    ObjectManager::Instance()->addObject(ship1);
    ship1->setPosition({50.f, 700.f});
    ship1->getSprite()->setRotation(-90.f);

    Ship* ship2 = new Ship("Ship2");
    ObjectManager::Instance()->addObject(ship2);
    ship2->getSprite()->setColor(sf::Color::Red);
    ship2->getSprite()->rotate(180.f);
    ship2->setPosition({300.f, 400.f});

    Ship* ship3 = new Ship("Ship2");
    ObjectManager::Instance()->addObject(ship3);
    ship3->getSprite()->setColor(sf::Color::Red);
    ship3->getSprite()->rotate(180.f);
    ship3->setPosition({800.f, 200.f});


    ObjectPool* ship1Bullets = new ObjectPool(ship1->getName() + "Bullets", 3, new Bullet("Bullet1", ship1));
    // ObjectPool* ship2Bullets = new ObjectPool(ship2->getName() + "Bullets", 3, new Bullet("Bullet2", ship2));

    ship1Bullets->initialize();
    // ship2Bullets->initialize();

    ObjectPoolManager::Instance()->registerPool(ship1Bullets);
    // ObjectPoolManager::Instance()->registerPool(ship2Bullets);

}
