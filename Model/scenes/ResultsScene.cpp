
#include "ResultsScene.hpp"

using namespace scenes;

ResultsScene::ResultsScene() : Scene(SceneTag::RESULTS){}

void ResultsScene::onLoadResources(){
    TextureManager::Instance()->loadTexture(TextureType::BACKGROUND, "MainMenu");
    sf::Font font = sf::Font();
    font.loadFromFile("View/Fonts/Astrud-Regular.ttf");
    this->uiFont = font;
}

void ResultsScene::onLoadObjects(){
    Background* background = new Background("Background");
    ObjectManager::Instance()->addObject(background);
    background->getSprite()->setScale(2.f, 2.f);
    
    TextElement* backPrompt = new TextElement("Prompt", "", &this->uiFont, PROMPT_FONT_SIZE, ObjectType::PROMPT);
    ObjectManager::Instance()->addObject(backPrompt);
    backPrompt->setText("< Press SPACE to go back to Main Menu >", true);
    backPrompt->setPosition(PROMPT_POSITION);
    backPrompt->attachComponent(new ResultsPromptInput(backPrompt->getName() + "Input"));
    backPrompt->attachComponent(new ResultsPromptScript(backPrompt->getName() + "Script"));
}