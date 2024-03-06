
#include "SceneManager.hpp"

using namespace managers;

SceneManager::SceneManager() :
    activeScene(NULL), loadNewScene(false), sceneToLoad(SceneTag::NONE)
{
    
}

void SceneManager::registerScene(Scene* scene){
    this->scenes[scene->getTag()] = scene;
}

void SceneManager::loadScene(SceneTag tag){
    this->loadNewScene = true;
    this->sceneToLoad = tag;
}

void SceneManager::unloadScene(){
    ObjectManager::Instance()->deleteAllObjects();

    if(this->activeScene != NULL)
        activeScene->onUnloadResources();
}

void SceneManager::checkLoadScene(){
    if(!this->loadNewScene)
        return;

    this->unloadScene();
    this->activeScene = this->scenes[this->sceneToLoad];
    this->activeScene->onLoadResources();
    this->activeScene->onLoadObjects();
    this->loadNewScene = false;
}

bool SceneManager::isLoaded(SceneTag tag){
    return (tag == this->activeScene->getTag());
}


/* SINGLETON CODE */
SceneManager* SceneManager::SHARED_INSTANCE = NULL;
SceneManager::SceneManager(const SceneManager&){}
SceneManager* SceneManager::Instance(){
    if(SHARED_INSTANCE == NULL)
        SHARED_INSTANCE = new SceneManager();

    return SHARED_INSTANCE;
}