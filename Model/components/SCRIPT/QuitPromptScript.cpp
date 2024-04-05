
#include "QuitPromptScript.hpp"

using namespace components;

QuitPromptScript::QuitPromptScript(std::string name) :
    GenericScript(name){}

void QuitPromptScript::perform(){
    QuitPromptInput* input = (QuitPromptInput*) this->getOwner()->getComponent(this->getOwner()->getName() + "Input");
    if(input == NULL){
        std::cout << "Dependency Missing!" << std::endl;
        return;
    }

    if(input->isSpacePressed()){
        input->resetSpacePressed();
        SceneManager::Instance()->loadScene(SceneTag::ARENA);
        ((ArenaScene*)SceneManager::Instance()->getScene(SceneTag::ARENA))->passMap(
            ((MainMenuScene*)SceneManager::Instance()->getScene(SceneTag::MAIN_MENU))->getMap()
        );
    }

    if(input->isEscapePressed()){
        input->resetEscapePressed();
        SceneManager::Instance()->loadScene(SceneTag::MAIN_MENU);
    }
}