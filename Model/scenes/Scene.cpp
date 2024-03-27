
#include "Scene.hpp"

using namespace scenes;
Scene::Scene(SceneTag tag) :
    tag(tag){}

SceneTag Scene::getTag(){
    return this->tag;
}

void Scene::onUnload(){}