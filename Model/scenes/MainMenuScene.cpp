
#include "MainMenuScene.hpp"

using namespace scenes;

MainMenuScene::MainMenuScene() : 
    Scene(SceneTag::MAIN_MENU){}

void MainMenuScene::onLoadResources(){
    TextureManager::Instance()->loadTexture(TextureType::TANK_ROLL_RIGHT, "Frame1");
    TextureManager::Instance()->loadTexture(TextureType::TANK_ROLL_RIGHT, "Frame2");
    TextureManager::Instance()->loadTexture(TextureType::TANK_ROLL_RIGHT, "Frame3");
    TextureManager::Instance()->loadTexture(TextureType::TANK_ROLL_RIGHT, "Frame4");
}

void MainMenuScene::onLoadObjects(){
    ObjectManager::Instance()->addObject((GameObject*) new Entity());
}

void MainMenuScene::onUnloadResources(){
    
}
