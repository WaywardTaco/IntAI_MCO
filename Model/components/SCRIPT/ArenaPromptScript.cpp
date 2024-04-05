
#include "ArenaPromptScript.hpp"

using namespace components;

ArenaPromptScript::ArenaPromptScript(std::string name) :
    GenericScript(name){}

void ArenaPromptScript::perform(){
    ArenaPromptInput* input = (ArenaPromptInput*) this->getOwner()->getComponent(this->getOwner()->getName() + "Input");
    if(input == NULL){
        std::cout << "Dependency Missing!" << std::endl;
        return;
    }

    if(input->isEscapePressed()){
        input->resetEscapePressed();
        SceneManager::Instance()->loadScene(SceneTag::QUIT);
    }
}