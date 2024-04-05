
#include "SettingPromptScript.hpp"

using namespace components;

SettingPromptScript::SettingPromptScript(std::string name) :
    GenericScript(name){}

void SettingPromptScript::perform(){
    SettingPromptInput* input = (SettingPromptInput*) this->getOwner()->getComponent(this->getOwner()->getName() + "Input");
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
}