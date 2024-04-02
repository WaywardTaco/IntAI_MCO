
#pragma once

#include "Scene.hpp"
#include "../uiElements/Background.hpp"
#include "../uiElements/TextElement.hpp"
#include "../components/INPUT/ResultsPromptInput.hpp"
#include "../components/SCRIPT/ResultsPromptScript.hpp"

namespace scenes {
    using namespace uiElements;
    using namespace components;
    class ResultsScene : public Scene {
        private:
            sf::Font uiFont;
        public:
            ResultsScene();
            
            void onLoadResources();
            void onLoadObjects();
    };
}