
#include "SettingPromptScript.hpp"

using namespace components;

SettingPromptScript::SettingPromptScript(std::string name) :
    GenericScript(name), count(0){}

void SettingPromptScript::perform(){
    SettingPromptInput* input = (SettingPromptInput*) this->getOwner()->getComponent(this->getOwner()->getName() + "Input");
    SettingsScene* scene = (SettingsScene*) SceneManager::Instance()->getScene(SceneTag::SETTINGS);

    if(input == NULL){
        std::cout << "Dependency Missing!" << std::endl;
        return;
    }

    if(input->isSpacePressed()){
     
    }

    if(input->isEscapePressed()){
        input->resetEscapePressed();
        SceneManager::Instance()->loadScene(SceneTag::MAIN_MENU);
    }

    if(input->isLeftPressed()){
        input->resetLeftPressed();
        scene->switchCheck();
        ControlManager::getInstance()->setControlScheme(this->count);
    }

    if(input->isRightPressed()){
        input->resetRightPressed();
        scene->switchCheck();
        ControlManager::getInstance()->setControlScheme(this->count);
    }
}