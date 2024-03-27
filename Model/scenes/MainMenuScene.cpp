
#include "MainMenuScene.hpp"

using namespace scenes;

MainMenuScene::MainMenuScene() : 
    Scene(SceneTag::MAIN_MENU){}

void MainMenuScene::onLoadResources(){
    TextureManager::Instance()->loadTexture(TextureType::BACKGROUND, "MainMenu");
}

void MainMenuScene::onLoadObjects(){
    Background* background = new Background("Background");
    ObjectManager::Instance()->addObject(background);
}
