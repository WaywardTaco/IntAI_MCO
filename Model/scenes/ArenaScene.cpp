
#include "ArenaScene.hpp"

using namespace scenes;

ArenaScene::ArenaScene() : 
    Scene(SceneTag::ARENA),
    currentMap(MapTypes::PLAIN){}

void ArenaScene::onLoadResources(){
    AudioManager::Instance()->loadMusic(MusicType::BACKGROUND, "View/Music/game_music.wav");
    AudioManager::Instance()->loadSound(SoundType::BULLET_SHOOT, "View/Sounds/shoot_sfx.wav");

    TextureManager::Instance()->loadTexture(TextureType::SHIP, "Basic");
    TextureManager::Instance()->loadTexture(TextureType::BULLET, "Frame1");
    TextureManager::Instance()->loadTexture(TextureType::BACKGROUND, "PlainBG");
    TextureManager::Instance()->loadTexture(TextureType::BACKGROUND, "MineBG");
    TextureManager::Instance()->loadTexture(TextureType::BACKGROUND, "ChaosBG");
    TextureManager::Instance()->loadTexture(TextureType::BACKGROUND, "ShieldBG");
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
    AudioManager::Instance()->playMusic(MusicType::BACKGROUND, 30.f);

    float  
        maxMines = 0,
        maxChaos = 0,
        maxShields = 0,
        maxBases = 0;

    switch(this->currentMap){
        case MapTypes::PLAIN:
            maxMines = MAP_PLAIN_MAX_MINES;
            maxChaos = MAP_PLAIN_MAX_CHAOS;
            maxShields = MAP_PLAIN_MAX_SHIELDS;
            maxBases = MAP_PLAIN_MAX_BASES;
            break;
        case MapTypes::CHAOS:
            maxMines = MAP_CHAOS_MAX_MINES;
            maxChaos = MAP_CHAOS_MAX_CHAOS;
            maxShields = MAP_CHAOS_MAX_SHIELDS;
            maxBases = MAP_CHAOS_MAX_BASES;
            break;
        case MapTypes::MINE:
            maxMines = MAP_MINE_MAX_MINES;
            maxChaos = MAP_MINE_MAX_CHAOS;
            maxShields = MAP_MINE_MAX_SHIELDS;
            maxBases = MAP_MINE_MAX_BASES;
            break;
        case MapTypes::SHIELD:
            maxMines = MAP_SHIELD_MAX_MINES;
            maxChaos = MAP_SHIELD_MAX_CHAOS;
            maxShields = MAP_SHIELD_MAX_SHIELDS;
            maxBases = MAP_SHIELD_MAX_BASES;
            break;
    }

    Background* background = new Background("Background");
   
    ObjectManager::Instance()->addObject(background);
    background->attachComponent(new ArenaPromptInput(background->getName() + "Input"));
    background->attachComponent(new ArenaPromptScript(background->getName() + "Script"));

    if(this->currentMap == MapTypes::MINE){
        background->iterateFrames();
    }
    if(this->currentMap == MapTypes::CHAOS){
        background->iterateFrames();
        background->iterateFrames();
    }
    if(this->currentMap == MapTypes::SHIELD){
        background->iterateFrames();
        background->iterateFrames();
        background->iterateFrames();
    }

    ObjectManager::Instance()->addObject(new MatchTracker("MatchTracker"));

    ObjectManager::Instance()->addObject(
        new Spawner("PowerupSpawner", 
            new ObjectPool("MinePool", maxMines, 
            new Powerup("Mine", PowerupType::SPACE_MINE)), 
            new ObjectPool("ChaosPool", maxChaos, 
            new Powerup("Chaos", PowerupType::BASE_CHAOS)),
            new ObjectPool("ShieldPool", maxShields, 
            new Powerup("Shield", PowerupType::BASE_INVINCIBILITY))
        )
    );

    for(int i = 0; i < maxBases; i++){
        Base* base = new Base("BaseE" + std::to_string(i), ObjectTeams::ENEMY);
        ObjectManager::Instance()->addObject(base);
        Utility::setRandomLoc(base);
        base->getSprite()->setColor(sf::Color::Red);
    }

    for(int i = 0; i < maxBases; i++){
        Base* base = new Base("BaseP" + std::to_string(i), ObjectTeams::PLAYER);
        ObjectManager::Instance()->addObject(base);
        Utility::setRandomLoc(base);
    }

    Base* enemySpawnBase = (Base*) ObjectManager::Instance()->findObjectByName("BaseE" + std::to_string(Utility::getRandomNumber(0, maxBases - 1)));

    float 
        enemyXSpawn = Utility::getRandomNumber(-SHIP_SPAWN_RADIUS, SHIP_SPAWN_RADIUS) + enemySpawnBase->getPosition().x,
        enemyYSpawn = Utility::getRandomNumber(-SHIP_SPAWN_RADIUS, SHIP_SPAWN_RADIUS) + enemySpawnBase->getPosition().y;

    if(enemyXSpawn < WINDOW_BORDER)
        enemyXSpawn = WINDOW_BORDER;
    if(enemyXSpawn > WINDOW_WIDTH - WINDOW_BORDER)
        enemyXSpawn = WINDOW_WIDTH - WINDOW_BORDER;
    if(enemyYSpawn < WINDOW_BORDER)
        enemyYSpawn = WINDOW_BORDER;
    if(enemyYSpawn > WINDOW_HEIGHT - WINDOW_BORDER)
        enemyYSpawn = WINDOW_HEIGHT - WINDOW_BORDER;

    Base* playerSpawnBase = (Base*) ObjectManager::Instance()->findObjectByName("BaseP" + std::to_string(Utility::getRandomNumber(0, maxBases - 1)));

    float 
        playerXSpawn = Utility::getRandomNumber(-SHIP_SPAWN_RADIUS, SHIP_SPAWN_RADIUS) + playerSpawnBase->getPosition().x,
        playerYSpawn = Utility::getRandomNumber(-SHIP_SPAWN_RADIUS, SHIP_SPAWN_RADIUS) + playerSpawnBase->getPosition().y;

    if(playerXSpawn < WINDOW_BORDER)
        playerXSpawn = WINDOW_BORDER;
    if(playerXSpawn > WINDOW_WIDTH - WINDOW_BORDER)
        playerXSpawn = WINDOW_WIDTH - WINDOW_BORDER;
    if(playerYSpawn < WINDOW_BORDER)
        playerYSpawn = WINDOW_BORDER;
    if(playerYSpawn > WINDOW_HEIGHT - WINDOW_BORDER)
        playerYSpawn = WINDOW_HEIGHT - WINDOW_BORDER;
        
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

void ArenaScene::passMap(MapTypes map){
    this->currentMap = map;
}

MapTypes ArenaScene::getMap(){
    return this->currentMap;
}