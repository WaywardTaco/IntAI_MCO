
#pragma once

#include "Scene.hpp"
#include "../entities/Entity.hpp"

namespace scenes {
    using namespace entities;
    class MainMenuScene : public Scene {
        public:
            MainMenuScene();

            void onLoadResources();
            void onLoadObjects();
            void onUnloadResources();
    };
}