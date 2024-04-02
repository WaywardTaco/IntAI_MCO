
#pragma once

#include "Scene.hpp"
#include "../uiElements/Background.hpp"
#include "../uiElements/TextElement.hpp"
#include "../components/INPUT/MainMenuPromptInput.hpp"
#include "../components/SCRIPT/MainMenuPromptScript.hpp"

namespace scenes {
    using namespace uiElements;
    using namespace components;
    class MainMenuScene : public Scene {
        private:
            sf::Font uiFont;

        public:
            MainMenuScene();

            void onLoadResources();
            void onLoadObjects();
    };
}