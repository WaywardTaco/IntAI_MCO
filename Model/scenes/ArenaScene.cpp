
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
    TextureManager::Instance()->loadTexture(TextureType::POWERUP, "Shield");
    TextureManager::Instance()->loadTexture(TextureType::BASE, "Normal");
    TextureManager::Instance()->loadTexture(TextureType::BASE, "Shielded");
    TextureManager::Instance()->loadTexture(TextureType::BASE, "Ruined");
    sf::Font font = sf::Font();
    font.loadFromFile("View/Fonts/Astrud-Regular.ttf");
    this->uiFont = font;
}

void ArenaScene::onLoadObjects(){
    Background* background = new Background("Background");
    ObjectManager::Instance()->addObject(background);
    background->getSprite()->setScale(2.f, 2.f);
        
    ObjectManager::Instance()->addObject(new MatchTracker("MatchTracker"));
    
    ObjectManager::Instance()->addObject(
        new Spawner("PowerupSpawner", 
            new ObjectPool("MinePool", MAX_MINES, 
            new Powerup("Mine", PowerupType::SPACE_MINE)), 
            new ObjectPool("ChaosPool", MAX_CHAOS, 
            new Powerup("Chaos", PowerupType::BASE_CHAOS)),
            new ObjectPool("ShieldPool", MAX_SHIELDS, 
            new Powerup("Shield", PowerupType::BASE_INVINCIBILITY))
        )
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

    Base* enemySpawnBase = NULL;
    switch(Utility::getRandomNumber(0, 2)){
        case 0:
            enemySpawnBase = base1;
            break;
        case 1:
            enemySpawnBase = base2;
            break;
        case 2:
            enemySpawnBase = base3;
            break;
    }

    float 
        enemyXSpawn = Utility::getRandomNumber(-SHIP_SPAWN_RADIUS, SHIP_SPAWN_RADIUS) + enemySpawnBase->getPosition().x,
        enemyYSpawn = Utility::getRandomNumber(-SHIP_SPAWN_RADIUS, SHIP_SPAWN_RADIUS) + enemySpawnBase->getPosition().y;

    if(enemyXSpawn < 0.f)
        enemyXSpawn = 0.f;
    if(enemyXSpawn > WINDOW_WIDTH)
        enemyXSpawn = WINDOW_WIDTH;
    if(enemyYSpawn < 0.f)
        enemyYSpawn = 0.f;
    if(enemyYSpawn > WINDOW_HEIGHT)
        enemyYSpawn = WINDOW_HEIGHT;

    Base* playerSpawnBase = NULL;
    switch(Utility::getRandomNumber(0, 2)){
        case 0:
            playerSpawnBase = base4;
            break;
        case 1:
            playerSpawnBase = base5;
            break;
        case 2:
            playerSpawnBase = base6;
            break;
    }

    float 
        playerXSpawn = Utility::getRandomNumber(-SHIP_SPAWN_RADIUS, SHIP_SPAWN_RADIUS) + playerSpawnBase->getPosition().x,
        playerYSpawn = Utility::getRandomNumber(-SHIP_SPAWN_RADIUS, SHIP_SPAWN_RADIUS) + playerSpawnBase->getPosition().y;

    if(playerXSpawn < 0.f)
        playerXSpawn = 0.f;
    if(playerXSpawn > WINDOW_WIDTH)
        playerXSpawn = WINDOW_WIDTH;
    if(playerYSpawn < 0.f)
        playerYSpawn = 0.f;
    if(playerYSpawn > WINDOW_HEIGHT)
        playerYSpawn = WINDOW_HEIGHT;
        
    EnemyShip* enemy = new EnemyShip("Enemy", {enemyXSpawn, enemyYSpawn});
    ObjectManager::Instance()->addObject(enemy);

    PlayerShip* player = new PlayerShip("Ship1", {playerXSpawn, playerYSpawn});
    ObjectManager::Instance()->addObject(player);

    ScoreUI* playerKills = new ScoreUI("PlayerScore", ObjectTeams::PLAYER, &this->uiFont);
    ObjectManager::Instance()->addObject(playerKills);
    playerKills->setPosition(PLAYER_SCORE_POSITION);    

    ScoreUI* enemyKills = new ScoreUI("EnemyScore", ObjectTeams::ENEMY, &this->uiFont);
    ObjectManager::Instance()->addObject(enemyKills);
    enemyKills->setPosition(ENEMY_SCORE_POSITION);    

    TimerUI* timer = new TimerUI("TimerUI", &this->uiFont);
    ObjectManager::Instance()->addObject(timer);
    timer->setPosition(TIMER_UI_POSITION);    
}
