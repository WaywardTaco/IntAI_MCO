
#include "MainMenuPromptScript.hpp"

using namespace components;

MainMenuPromptScript::MainMenuPromptScript(std::string name) :
    GenericScript(name){}

void MainMenuPromptScript::perform(){
    MainMenuPromptInput* input = (MainMenuPromptInput*) this->getOwner()->getComponent(this->getOwner()->getName() + "Input");
    if(input == NULL){
        std::cout << "Dependency Missing!" << std::endl;
        return;
    }

    if(input->isSpacePressed()){
        input->resetSpacePressed();
        SceneManager::Instance()->loadScene(SceneTag::ARENA);
    }
    if(input->isEscapePressed()){
        Game::Instance()->close();
    }

}