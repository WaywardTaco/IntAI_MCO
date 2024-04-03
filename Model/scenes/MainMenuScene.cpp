
#include "MainMenuScene.hpp"

using namespace scenes;

MainMenuScene::MainMenuScene() : 
    Scene(SceneTag::MAIN_MENU),
    currentMap(MapTypes::PLAIN){}

void MainMenuScene::onLoadResources(){
    TextureManager::Instance()->loadTexture(TextureType::BACKGROUND, "PlainBG");
    TextureManager::Instance()->loadTexture(TextureType::BACKGROUND, "MineBG");
    TextureManager::Instance()->loadTexture(TextureType::BACKGROUND, "ChaosBG");
    TextureManager::Instance()->loadTexture(TextureType::BACKGROUND, "ShieldBG");
    sf::Font font = sf::Font();
    font.loadFromFile("View/Fonts/Astrud-Regular.ttf");
    this->uiFont = font;
}

void MainMenuScene::onLoadObjects(){
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

    TextElement* startPrompt = new TextElement("Prompt", "", &this->uiFont, PROMPT_FONT_SIZE, ObjectType::PROMPT);
    ObjectManager::Instance()->addObject(startPrompt);
    startPrompt->setText("[ Press SPACE to Start ]", true);
    startPrompt->setPosition(PROMPT_POSITION);
    startPrompt->attachComponent(new MainMenuPromptInput(startPrompt->getName() + "Input"));
    startPrompt->attachComponent(new MainMenuPromptScript(startPrompt->getName() + "Script"));

    TextElement* mapSelect = new TextElement("MapSelect", "", &this->uiFont, MAP_SELECT_FONT_SIZE, ObjectType::PROMPT);
    ObjectManager::Instance()->addObject(mapSelect);
    switch(this->currentMap){
        case MapTypes::PLAIN:
            mapSelect->setText("<= The Vast Expanse =>", true);
            break;
        case MapTypes::MINE:
            mapSelect->setText("<= Planet Vaspar Orbit =>", true);
            break;
        case MapTypes::CHAOS:
            mapSelect->setText("<= Proxi Elumnar =>", true);
            break;
        case MapTypes::SHIELD:
            mapSelect->setText("<= U.C.G. Headquarters =>", true);
            break;
    }
    mapSelect->setPosition({PROMPT_POSITION.x, PROMPT_POSITION.y + MAP_SELECT_OFFSET});
    mapSelect->attachComponent(new MapSelectPromptInput(mapSelect->getName() + "Input"));
    mapSelect->attachComponent(new MapSelectPromptScript(mapSelect->getName() + "Script"));

    TextElement* title = new TextElement("Title", "", &this->uiFont, TITLE_FONT_SIZE, ObjectType::PLAIN_TEXT);
    ObjectManager::Instance()->addObject(title);
    title->setText(GAME_NAME, true);
    title->setPosition(TITLE_POSITION);

    TextElement* escape = new TextElement("Escape", "", &this->uiFont, ESCAPE_FONT_SIZE, ObjectType::PLAIN_TEXT);
    ObjectManager::Instance()->addObject(escape);
    escape->setText("=== Press Escape to Exit ===", true);
    escape->setPosition({PROMPT_POSITION.x, PROMPT_POSITION.y + MAIN_MENU_ESCAPE_OFFSET});
}

void MainMenuScene::passMap(MapTypes map){
    this->currentMap = map;
}

MapTypes MainMenuScene::getMap(){
    return this->currentMap;
}
