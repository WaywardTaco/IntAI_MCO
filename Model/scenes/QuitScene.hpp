
#pragma once

#include "Scene.hpp"
#include "../enums/MapTypes.hpp"
#include "../uiElements/Background.hpp"
#include "../uiElements/TextElement.hpp"
#include "../components/INPUT/QuitPromptInput.hpp"
#include "../components/INPUT/MapSelectPromptInput.hpp"
#include "../components/SCRIPT/QuitPromptScript.hpp"
#include "../components/SCRIPT/MapSelectPromptScript.hpp"

namespace scenes {
    using namespace uiElements;
    using namespace components;
    class QuitScene : public Scene {
        private:
            sf::Font uiFont;
            MapTypes currentMap;

        public:
            QuitScene();

            void onLoadResources();
            void onLoadObjects();
            void passMap(MapTypes map);
            MapTypes getMap();
    };
}