
#include "ArenaScene.hpp"

using namespace scenes;

ArenaScene::ArenaScene() 
    : Scene(SceneTag::ARENA){}

void ArenaScene::onLoadResources(){
    TextureManager::Instance()->loadTexture(TextureType::SHIP, "Basic");
    TextureManager::Instance()->loadTexture(TextureType::BULLET, "Frame1");
    TextureManager::Instance()->loadTexture(TextureType::BACKGROUND, "MainMenu");
    TextureManager::Instance()->loadTexture(TextureType::POWERUP, "Mine");
    TextureManager::Instance()->loadTexture(TextureType::POWERUP, "Chaos");
    TextureManager::Instance()->loadTexture(TextureType::BASE, "Normal");
    TextureManager::Instance()->loadTexture(TextureType::BASE, "Ruined");
}

void ArenaScene::onLoadObjects(){
    Background* background = new Background("Background");
    ObjectManager::Instance()->addObject(background);
    background->getSprite()->setScale(2.f, 2.f);
        
    ObjectManager::Instance()->addObject(
        new Spawner("MineSpawner", 
        new ObjectPool("MinePool", 7, 
        new Powerup("Mine", PowerupType::SPACE_MINE)))
    );
        
    ObjectManager::Instance()->addObject(
        new Spawner("ChaosSpawner", 
        new ObjectPool("ChaosPool", 2, 
        new Powerup("Chaos", PowerupType::BASE_CHAOS)))
    );

    Base* base1 = new Base("Base1", ObjectTeams::ENEMY);
    ObjectManager::Instance()->addObject(base1);
    Utility::setRandomLoc(base1);
    base1->getSprite()->setColor(sf::Color::Red);

    Base* base2 = new Base("Base2", ObjectTeams::ENEMY);
    ObjectManager::Instance()->addObject(base2);
    Utility::setRandomLoc(base2);
    base2->getSprite()->setColor(sf::Color::Red);

    Base* base3 = new Base("Base3", ObjectTeams::ENEMY);
    ObjectManager::Instance()->addObject(base3);
    Utility::setRandomLoc(base3);
    base3->getSprite()->setColor(sf::Color::Red);

    Base* base4 = new Base("Base4", ObjectTeams::PLAYER);
    ObjectManager::Instance()->addObject(base4);
    Utility::setRandomLoc(base4);

    Base* base5 = new Base("Base5", ObjectTeams::PLAYER);
    ObjectManager::Instance()->addObject(base5);
    Utility::setRandomLoc(base5);

    Base* base6 = new Base("Base6", ObjectTeams::PLAYER);
    ObjectManager::Instance()->addObject(base6);
    Utility::setRandomLoc(base6);

    EnemyShip* enemy = new EnemyShip("Enemy");
    ObjectManager::Instance()->addObject(enemy);
    Utility::setRandomLoc(enemy);

    PlayerShip* player = new PlayerShip("Ship1");
    ObjectManager::Instance()->addObject(player);
    Utility::setRandomLoc(player);
    player->getSprite()->setRotation(90.f);
}
