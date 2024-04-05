
#include "SettingsScene.hpp"

using namespace scenes;

SettingsScene::SettingsScene() : 
    Scene(SceneTag::SETTINGS),
    currentMap(MapTypes::PLAIN){}

void SettingsScene::onLoadResources(){
    TextureManager::Instance()->loadTexture(TextureType::BACKGROUND, "PlainBG");
    TextureManager::Instance()->loadTexture(TextureType::BACKGROUND, "MineBG");
    TextureManager::Instance()->loadTexture(TextureType::BACKGROUND, "ChaosBG");
    TextureManager::Instance()->loadTexture(TextureType::BACKGROUND, "ShieldBG");
    sf::Font font = sf::Font();
    font.loadFromFile("View/Fonts/Astrud-Regular.ttf");
    this->uiFont = font;
}

void SettingsScene::onLoadObjects(){

    TextElement* startPrompt = new TextElement("Prompt", "", &this->uiFont, PROMPT_FONT_SIZE, ObjectType::PROMPT);
    ObjectManager::Instance()->addObject(startPrompt);
    startPrompt->setText("[ Press Escape to Exit ]", true);
    startPrompt->setPosition(PROMPT_POSITION);
    startPrompt->attachComponent(new SettingPromptInput(startPrompt->getName() + "Input"));
    startPrompt->attachComponent(new SettingPromptScript(startPrompt->getName() + "Script"));

    TextElement* title = new TextElement("Title", "", &this->uiFont, TITLE_FONT_SIZE, ObjectType::PLAIN_TEXT);
    ObjectManager::Instance()->addObject(title);
    title->setText("Settings", true);
    title->setPosition(TITLE_POSITION);

    TextElement* escape = new TextElement("Escape", "", &this->uiFont, ESCAPE_FONT_SIZE, ObjectType::PLAIN_TEXT);
    ObjectManager::Instance()->addObject(escape);
    escape->setText("[ Press Space to Return ]", true);
    escape->setPosition({PROMPT_POSITION.x, PROMPT_POSITION.y + MAIN_MENU_ESCAPE_OFFSET});

}


void SettingsScene::passMap(MapTypes map){
    this->currentMap = map;
}

MapTypes SettingsScene::getMap(){
    return this->currentMap;
}