
#include "ResultsScene.hpp"

using namespace scenes;

ResultsScene::ResultsScene() : 
    Scene(SceneTag::RESULTS),
    currentMap(MapTypes::PLAIN){}

void ResultsScene::onLoadResources(){
    TextureManager::Instance()->loadTexture(TextureType::BACKGROUND, "PlainBG");
    TextureManager::Instance()->loadTexture(TextureType::BACKGROUND, "MineBG");
    TextureManager::Instance()->loadTexture(TextureType::BACKGROUND, "ChaosBG");
    TextureManager::Instance()->loadTexture(TextureType::BACKGROUND, "ShieldBG");
    sf::Font font = sf::Font();
    font.loadFromFile("View/Fonts/Astrud-Regular.ttf");
    this->uiFont = font;
}

void ResultsScene::onLoadObjects(){
    Background* background = new Background("Background");
    ObjectManager::Instance()->addObject(background);
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
    
    TextElement* backPrompt = new TextElement("Prompt", "", &this->uiFont, PROMPT_FONT_SIZE, ObjectType::PROMPT);
    ObjectManager::Instance()->addObject(backPrompt);
    backPrompt->setText("< Press Esc to go back to Main Menu >", true);
    backPrompt->setPosition(PROMPT_POSITION);
    backPrompt->attachComponent(new ResultsPromptInput(backPrompt->getName() + "Input"));
    backPrompt->attachComponent(new ResultsPromptScript(backPrompt->getName() + "Script"));

    if(this->timeLeft <= 0.f){
        TextElement* gameOver = new TextElement("GameOver", "", &this->uiFont, RESULTS_GAME_OVER_FONT_SIZE, ObjectType::PLAIN_TEXT);
        ObjectManager::Instance()->addObject(gameOver);
        gameOver->setText("Time is Up!", true);
        gameOver->setPosition({RESULTS_WINNER_CENTER.x, RESULTS_WINNER_CENTER.y + RESULTS_GAME_OVER_OFFSET});
    } else if (this->playerBasesLeft <= 0.f) {
        TextElement* gameOver = new TextElement("GameOver", "", &this->uiFont, RESULTS_GAME_OVER_FONT_SIZE, ObjectType::PLAIN_TEXT);
        ObjectManager::Instance()->addObject(gameOver);
        gameOver->setText("Your Bases Were Destroyed!", true);
        gameOver->setPosition({RESULTS_WINNER_CENTER.x, RESULTS_WINNER_CENTER.y + RESULTS_GAME_OVER_OFFSET});
    } else {
        TextElement* gameOver = new TextElement("GameOver", "", &this->uiFont, RESULTS_GAME_OVER_FONT_SIZE, ObjectType::PLAIN_TEXT);
        ObjectManager::Instance()->addObject(gameOver);
        gameOver->setText("Destroyed All Enemy Bases!", true);
        gameOver->setPosition({RESULTS_WINNER_CENTER.x, RESULTS_WINNER_CENTER.y + RESULTS_GAME_OVER_OFFSET});
    }

    if(this->winner == ObjectTeams::PLAYER){
        TextElement* winner = new TextElement("Winner", "", &this->uiFont, RESULTS_WINNER_FONT_SIZE, ObjectType::PLAIN_TEXT);
        ObjectManager::Instance()->addObject(winner);
        winner->setText("YOU WIN", true);
        winner->setPosition({RESULTS_WINNER_CENTER.x, RESULTS_WINNER_CENTER.y});
    } else if (this->winner == ObjectTeams::ENEMY){
        TextElement* winner = new TextElement("Winner", "", &this->uiFont, RESULTS_WINNER_FONT_SIZE, ObjectType::PLAIN_TEXT);
        ObjectManager::Instance()->addObject(winner);
        winner->setText("YOU LOSE", true);
        winner->setPosition({RESULTS_WINNER_CENTER.x, RESULTS_WINNER_CENTER.y});
    } else if (this->winner == ObjectTeams::TIE) {
        TextElement* winner = new TextElement("Winner", "", &this->uiFont, RESULTS_WINNER_FONT_SIZE, ObjectType::PLAIN_TEXT);
        ObjectManager::Instance()->addObject(winner);
        winner->setText("GAME TIED", true);
        winner->setPosition({RESULTS_WINNER_CENTER.x, RESULTS_WINNER_CENTER.y});
    }

    TextElement* score = new TextElement("Score", "", &this->uiFont, RESULTS_SCORE_FONT_SIZE, ObjectType::PLAIN_TEXT);
    ObjectManager::Instance()->addObject(score);
    score->setText("Score: " + std::to_string(this->playerScore), true);
    score->setPosition({RESULTS_WINNER_CENTER.x, RESULTS_WINNER_CENTER.y + RESULTS_SCORE_OFFSET});

    TextElement* kills = new TextElement("Kills", "", &this->uiFont, RESULTS_BREAKDOWN_FONT_SIZE, ObjectType::PLAIN_TEXT);
    ObjectManager::Instance()->addObject(kills);
    kills->setText(std::to_string(this->playerKills) + " Kills x " + std::to_string(SCORE_PER_KILL) + " = " + std::to_string(this->playerKills * SCORE_PER_KILL), true);
    kills->setPosition({RESULTS_WINNER_CENTER.x, RESULTS_WINNER_CENTER.y + RESULTS_BREAKDOWN_OFFSET + RESULTS_SCORE_OFFSET});

    TextElement* deaths = new TextElement("Deaths", "", &this->uiFont, RESULTS_BREAKDOWN_FONT_SIZE, ObjectType::PLAIN_TEXT);
    ObjectManager::Instance()->addObject(deaths);
    deaths->setText(std::to_string(this->enemyKills) + " Enemy Kills x " + std::to_string(SCORE_PER_DEATH) + " = " + std::to_string(this->enemyKills * SCORE_PER_DEATH), true);
    deaths->setPosition({RESULTS_WINNER_CENTER.x, RESULTS_WINNER_CENTER.y + RESULTS_BREAKDOWN_PADDING + RESULTS_BREAKDOWN_OFFSET + RESULTS_SCORE_OFFSET});

    TextElement* basesLeft = new TextElement("BasesLeft", "", &this->uiFont, RESULTS_BREAKDOWN_FONT_SIZE, ObjectType::PLAIN_TEXT);
    ObjectManager::Instance()->addObject(basesLeft);
    basesLeft->setText(std::to_string(this->playerBasesLeft) + " Bases Left x " + std::to_string(SCORE_PER_BASE_LEFT) + " = " + std::to_string(this->playerBasesLeft * SCORE_PER_BASE_LEFT), true);
    basesLeft->setPosition({RESULTS_WINNER_CENTER.x, RESULTS_WINNER_CENTER.y + 2*RESULTS_BREAKDOWN_PADDING + RESULTS_BREAKDOWN_OFFSET + RESULTS_SCORE_OFFSET});

    TextElement* enemyBaseseDestroyed = new TextElement("EnemyBasesDestroyed", "", &this->uiFont, RESULTS_BREAKDOWN_FONT_SIZE, ObjectType::PLAIN_TEXT);
    ObjectManager::Instance()->addObject(enemyBaseseDestroyed);
    enemyBaseseDestroyed->setText(std::to_string(this->playerBasesLeft) + " Bases Destroyed x " + std::to_string(SCORE_PER_BASE_DESTROYED) + " = " + std::to_string(this->enemyBasesDestroyed * SCORE_PER_BASE_DESTROYED), true);
    enemyBaseseDestroyed->setPosition({RESULTS_WINNER_CENTER.x, RESULTS_WINNER_CENTER.y + 3*RESULTS_BREAKDOWN_PADDING + RESULTS_BREAKDOWN_OFFSET + RESULTS_SCORE_OFFSET});

    TextElement* timeLeft = new TextElement("TimeLeft", "", &this->uiFont, RESULTS_BREAKDOWN_FONT_SIZE, ObjectType::PLAIN_TEXT);
    ObjectManager::Instance()->addObject(timeLeft);
    timeLeft->setText(std::to_string((int)this->timeLeft) + " Seconds Left x " + std::to_string(SCORE_PER_SECOND_LEFT) + " = " + std::to_string(((int)this->timeLeft) * SCORE_PER_SECOND_LEFT), true);
    timeLeft->setPosition({RESULTS_WINNER_CENTER.x, RESULTS_WINNER_CENTER.y + 4*RESULTS_BREAKDOWN_PADDING + RESULTS_BREAKDOWN_OFFSET + RESULTS_SCORE_OFFSET});
}

void ResultsScene::passMap(MapTypes map){
    this->currentMap = map;
}

MapTypes ResultsScene::getMap(){
    return this->currentMap;
}

void ResultsScene::passResults(float timeLeft, int playerKills, int enemyKills, int playerBases, int enemyBases){
    this->timeLeft = timeLeft;
    this->playerKills = playerKills;
    this->enemyKills = enemyKills;
    this->playerBasesLeft = playerBases;
    float totalBases = 0;
    switch(this->currentMap){
        case MapTypes::PLAIN:
            totalBases = MAP_PLAIN_MAX_BASES;
            break;
        case MapTypes::MINE:
            totalBases = MAP_PLAIN_MAX_BASES;
            break;
        case MapTypes::CHAOS:
            totalBases = MAP_CHAOS_MAX_BASES;
            break;
        case MapTypes::SHIELD:
            totalBases = MAP_SHIELD_MAX_BASES;
            break;
    }    

    this->enemyBasesDestroyed = totalBases - enemyBases;

    this->playerScore =
        SCORE_PER_KILL * playerKills +
        SCORE_PER_DEATH * enemyKills +
        SCORE_PER_BASE_LEFT * playerBases +
        SCORE_PER_BASE_DESTROYED * this->enemyBasesDestroyed +
        SCORE_PER_SECOND_LEFT * (int) timeLeft
    ;

    if(playerBases <= 0)
        this->winner = ObjectTeams::ENEMY;
    else if(enemyBases <= 0)
        this->winner = ObjectTeams::PLAYER;
    else if(playerBases > enemyBases)
        this->winner = ObjectTeams::PLAYER;
    else if(playerBases < enemyBases)
        this->winner = ObjectTeams::ENEMY;
    else if(playerKills > enemyKills)
        this->winner = ObjectTeams::PLAYER;
    else if(playerKills < enemyKills)
        this->winner = ObjectTeams::ENEMY;
    else {
        this->winner = ObjectTeams::TIE;
    }

}