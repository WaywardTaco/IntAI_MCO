
#pragma once

#include <unordered_map>
#include "../../Model/enums/SceneTag.hpp"
#include "../../Model/scenes/Scene.hpp"
#include "ObjectManager.hpp"

#include "../../Model/scenes/MainMenuScene.hpp"

namespace managers{
    using namespace scenes;
    class SceneManager{
        private:
            std::unordered_map<SceneTag, Scene*> scenes;
            Scene* activeScene;
            bool loadNewScene;
            SceneTag sceneToLoad;

        public:
            void registerScene(Scene* scene);
            void loadScene(SceneTag tag);
            void unloadScene();
            void checkLoadScene();
            bool isLoaded(SceneTag tag);

        /* SINGLETON CODE */
        private:
            static SceneManager* SHARED_INSTANCE;
            SceneManager();
            SceneManager(const SceneManager&);
            SceneManager& operator = (const SceneManager&);
        public:
            static SceneManager* Instance();
    };
}