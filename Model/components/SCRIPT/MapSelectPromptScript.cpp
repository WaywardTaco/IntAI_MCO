
#include "MapSelectPromptScript.hpp"

using namespace components;

MapSelectPromptScript::MapSelectPromptScript(std::string name) :
    GenericScript(name){};

void MapSelectPromptScript::perform(){
    TextElement* owner = (TextElement*) this->getOwner();
    MapSelectPromptInput* input = (MapSelectPromptInput*) this->getOwner()->getComponent(this->getOwner()->getName() + "Input");
    if(input == NULL){
        std::cout << "Dependency Missing!" << std::endl;
        return;
    }
    if(input->isGoNext()){
        input->resetFlags();
        switch(((MainMenuScene*)SceneManager::Instance()->getScene(SceneTag::MAIN_MENU))->getMap()){
            case MapTypes::PLAIN:
                owner->setText("<= Planet Vaspar Orbit =>", true);
                ((MainMenuScene*)SceneManager::Instance()->getScene(SceneTag::MAIN_MENU))->passMap(MapTypes::MINE);
                break;
            case MapTypes::MINE:
                owner->setText("<= Proxi Elumnar =>", true);
                ((MainMenuScene*)SceneManager::Instance()->getScene(SceneTag::MAIN_MENU))->passMap(MapTypes::CHAOS);
                break;
            case MapTypes::CHAOS:
                owner->setText("<= U.C.G. Headquarters =>", true);
                ((MainMenuScene*)SceneManager::Instance()->getScene(SceneTag::MAIN_MENU))->passMap(MapTypes::SHIELD);
                break;
            case MapTypes::SHIELD:
                owner->setText("<= The Vast Expanse =>", true);
                ((MainMenuScene*)SceneManager::Instance()->getScene(SceneTag::MAIN_MENU))->passMap(MapTypes::PLAIN);
                break;
        }
        ObjectManager::Instance()->findObjectByName("Background")->iterateFrames();
    }
    if(input->isGoPrev()){
        input->resetFlags();
        switch(((MainMenuScene*)SceneManager::Instance()->getScene(SceneTag::MAIN_MENU))->getMap()){
            case MapTypes::PLAIN:
                owner->setText("<= U.C.G. Headquarters =>", true);
                ((MainMenuScene*)SceneManager::Instance()->getScene(SceneTag::MAIN_MENU))->passMap(MapTypes::SHIELD);
                break;
            case MapTypes::MINE:
                owner->setText("<= The Vast Expanse =>", true);
                ((MainMenuScene*)SceneManager::Instance()->getScene(SceneTag::MAIN_MENU))->passMap(MapTypes::PLAIN);
                break;
            case MapTypes::CHAOS:
                owner->setText("<= Planet Vaspar Orbit =>", true);
                ((MainMenuScene*)SceneManager::Instance()->getScene(SceneTag::MAIN_MENU))->passMap(MapTypes::MINE);
                break;
            case MapTypes::SHIELD:
                owner->setText("<= Proxi Elumnar =>", true);
                ((MainMenuScene*)SceneManager::Instance()->getScene(SceneTag::MAIN_MENU))->passMap(MapTypes::CHAOS);
                break;
        }
        ObjectManager::Instance()->findObjectByName("Background")->iterateFrames();
        ObjectManager::Instance()->findObjectByName("Background")->iterateFrames();
        ObjectManager::Instance()->findObjectByName("Background")->iterateFrames();
    }
}