
#include "MainMenuScene.hpp"

using namespace scenes;

MainMenuScene::MainMenuScene() : 
    Scene(SceneTag::MAIN_MENU){}

void MainMenuScene::onLoadResources(){
    TextureManager::Instance()->loadTexture(TextureType::BACKGROUND, "MainMenu");
    sf::Font font = sf::Font();
    font.loadFromFile("View/Fonts/Astrud-Regular.ttf");
    this->uiFont = font;
}

void MainMenuScene::onLoadObjects(){
    Background* background = new Background("Background");
    ObjectManager::Instance()->addObject(background);
    background->getSprite()->setScale(2.f, 2.f);
    
    TextElement* startPrompt = new TextElement("Prompt", "", &this->uiFont, PROMPT_FONT_SIZE, ObjectType::PROMPT);
    ObjectManager::Instance()->addObject(startPrompt);
    startPrompt->setText("[ Press SPACE to Start ]", true);
    startPrompt->setPosition(PROMPT_POSITION);
    startPrompt->attachComponent(new MainMenuPromptInput(startPrompt->getName() + "Input"));
    startPrompt->attachComponent(new MainMenuPromptScript(startPrompt->getName() + "Script"));

    TextElement* title = new TextElement("Title", "", &this->uiFont, TITLE_FONT_SIZE, ObjectType::PLAIN_TEXT);
    ObjectManager::Instance()->addObject(title);
    title->setText(GAME_NAME, true);
    title->setPosition(TITLE_POSITION);

    TextElement* escape = new TextElement("Escape", "", &this->uiFont, ESCAPE_FONT_SIZE, ObjectType::PLAIN_TEXT);
    ObjectManager::Instance()->addObject(escape);
    escape->setText("=== Press Escape to Exit ===", true);
    escape->setPosition({PROMPT_POSITION.x, PROMPT_POSITION.y + MAIN_MENU_ESCAPE_OFFSET});
}
