
#pragma once

#include "Scene.hpp"
#include "../uiElements/Background.hpp"

namespace scenes {
    using namespace uiElements;
    class MainMenuScene : public Scene {
        public:
            MainMenuScene();

            void onLoadResources();
            void onLoadObjects();
    };
}