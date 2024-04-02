
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
    startPrompt->setText("< Press SPACE to Start >", true);
    startPrompt->setPosition(PROMPT_POSITION);
    startPrompt->attachComponent(new MainMenuPromptInput(startPrompt->getName() + "Input"));
    startPrompt->attachComponent(new MainMenuPromptScript(startPrompt->getName() + "Script"));
}
