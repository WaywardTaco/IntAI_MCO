#include "MainMenuScreen.hpp"

using namespace components;

MainMenuAction::MainMenuAction(std::string strName) : Component(strName, ComponentType::SCRIPT) {}

void MainMenuAction::perform() {
    BackgroundInput* pInput = (BackgroundInput*)this->getOwner()->findComponentByName(this->pOwner->getName() + " Input");/* [TODO] : Search for [BackgroundInput]. */

    if(pInput == NULL) {
        std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;
    }
    else {
        if(pInput->getInteract()) {
            /* [TODO] :
               Use [SceneManager] to switch to the [GameScene]. */
            SceneManager::getInstance()->loadScene(SceneTag::GAME_SCENE);
        }
    }   
}
