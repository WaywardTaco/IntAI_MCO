
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

    if(input->isEscapePressed()){
        input->resetEscapePress();
        SceneManager::Instance()->loadScene(SceneTag::MAIN_MENU);
        ((MainMenuScene*)SceneManager::Instance()->getScene(SceneTag::MAIN_MENU))->passMap(
            ((ResultsScene*)SceneManager::Instance()->getScene(SceneTag::RESULTS))->getMap()
        );
    }

}