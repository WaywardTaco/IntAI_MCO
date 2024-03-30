
#pragma once

#include <unordered_map>
#include "../../Model/enums/SceneTag.hpp"
#include "../../Model/scenes/Scene.hpp"
#include "ObjectManager.hpp"
#include "TextureManager.hpp"
#include "ColliderManager.hpp"

namespace managers{
    using namespace scenes;
    class SceneManager{
        private:
            std::unordered_map<SceneTag, Scene*> scenes;
            Scene* activeScene;
            bool loadNewScene;
            SceneTag sceneToLoad;

        public:
            void loadScene(SceneTag tag);
            void checkLoadScene();
            bool isLoaded(SceneTag tag);
            void registerScene(Scene* scene);

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