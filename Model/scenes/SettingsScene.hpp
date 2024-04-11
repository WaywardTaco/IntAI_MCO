
#pragma once

#include "Scene.hpp"
#include "../enums/MapTypes.hpp"
#include "../uiElements/Background.hpp"
#include "../uiElements/TextElement.hpp"
#include "../components/INPUT/SettingPromptInput.hpp"
#include "../components/INPUT/MapSelectPromptInput.hpp"
#include "../components/SCRIPT/SettingPromptScript.hpp"
#include "../components/SCRIPT/MapSelectPromptScript.hpp"

namespace scenes {
    using namespace uiElements;
    using namespace components;
    class SettingsScene : public Scene {
        private:
            sf::Font uiFont;
            MapTypes currentMap;
            bool check; //CHECK FOR PRINTING

        public:
            SettingsScene();

            void onLoadResources();
            void onLoadObjects();
            void createControlOptions(int count);
            void passMap(MapTypes map);
            MapTypes getMap();
    };
}