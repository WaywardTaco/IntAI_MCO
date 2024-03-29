
#include "ArenaScene.hpp"

using namespace scenes;

ArenaScene::ArenaScene() 
    : Scene(SceneTag::ARENA){}

void ArenaScene::onLoadResources(){
    TextureManager::Instance()->loadTexture(TextureType::SHIP, "Basic");
    TextureManager::Instance()->loadTexture(TextureType::BULLET, "Frame1");
    TextureManager::Instance()->loadTexture(TextureType::BACKGROUND, "MainMenu");
    TextureManager::Instance()->loadTexture(TextureType::POWERUP, "Mine");
    TextureManager::Instance()->loadTexture(TextureType::BASE, "Normal");
    TextureManager::Instance()->loadTexture(TextureType::BASE, "Ruined");
}

void ArenaScene::onLoadObjects(){
    Background* background = new Background("Background");
    background->getSprite()->setScale(2.f, 2.f);

    ObjectManager::Instance()->addObject(background);
    
    PlayerShip* ship1 = new PlayerShip("Ship1");
    ObjectManager::Instance()->addObject(ship1);
    ship1->setPosition({50.f, 700.f});
    ship1->getSprite()->setRotation(-90.f);

    Powerup* mine = new Powerup("Mine", PowerupType::SPACE_MINE);
    ObjectPool* mines = new ObjectPool("MinePool", 10, mine);
    
    Spawner* spawner = new Spawner("MineSpawner", mines);
    ObjectManager::Instance()->addObject(spawner);

    Base* base = new Base("Base", ObjectTeams::ENEMY);
    ObjectManager::Instance()->addObject(base);
    base->setPosition({300.f, 300.f});
    
    EnemyShip* enemy = new EnemyShip("Enemy");
    ObjectManager::Instance()->addObject(enemy);
    enemy->setPosition({500.f, 500.f});
    // ObjectManager::Instance()->addObject(mine1);
    // PlayerShip* ship2 = new PlayerShip("Ship2");
    // ObjectManager::Instance()->addObject(ship2);
    // ship2->getSprite()->setColor(sf::Color::Red);
    // ship2->getSprite()->rotate(180.f);
    // ship2->setPosition({300.f, 400.f});

    // PlayerShip* ship3 = new PlayerShip("Ship2");
    // ObjectManager::Instance()->addObject(ship3);
    // ship3->getSprite()->setColor(sf::Color::Red);
    // ship3->getSprite()->rotate(180.f);
    // ship3->setPosition({800.f, 200.f});


    // ObjectPool* ship2Bullets = new ObjectPool(ship2->getName() + "Bullets", 3, new Bullet("Bullet2", ship2));

    // ship2Bullets->initialize();

    // ObjectPoolManager::Instance()->registerPool(ship2Bullets);

}
