
#pragma once

#include "Scene.hpp"
#include "../enums/MapTypes.hpp"
#include "../enums/MusicType.hpp"
#include "../uiElements/Background.hpp"
#include "../uiElements/TextElement.hpp"
#include "../components/INPUT/MainMenuPromptInput.hpp"
#include "../components/INPUT/MapSelectPromptInput.hpp"
#include "../components/SCRIPT/MainMenuPromptScript.hpp"
#include "../components/SCRIPT/MapSelectPromptScript.hpp"
#include "../../Controller/managers/AudioManager.hpp"

namespace scenes {
    using namespace uiElements;
    using namespace components;
    using namespace managers;
    class MainMenuScene : public Scene {
        private:
            sf::Font uiFont;
            MapTypes currentMap;

        public:
            MainMenuScene();

            void onLoadResources();
            void onLoadObjects();
            void passMap(MapTypes map);
            MapTypes getMap();
    };
}