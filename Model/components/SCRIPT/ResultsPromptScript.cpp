
#include "ResultsPromptScript.hpp"

using namespace components;

ResultsPromptScript::ResultsPromptScript(std::string name) :
    GenericScript(name){}

void ResultsPromptScript::perform(){
    ResultsPromptInput* input = (ResultsPromptInput*) this->getOwner()->getComponent(this->getOwner()->getName() + "Input");
    if(input == NULL){
        std::cout << "Dependency Missing!" << std::endl;
        return;
    }

    if(input->isSpacePressed()){
        input->resetSpacePressed();
        SceneManager::Instance()->loadScene(SceneTag::MAIN_MENU);
    }

}