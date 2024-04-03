
#pragma once

#include "GenericScript.hpp"
#include "../../../Controller/managers/SceneManager.hpp"
#include "../../../Controller/managers/ObjectManager.hpp"
#include "../../enums/SceneTag.hpp"
#include "../../enums/MapTypes.hpp"
#include "../../scenes/MainMenuScene.hpp"
#include "../INPUT/MapSelectPromptInput.hpp"
#include "../../uiElements/TextElement.hpp"

namespace components {
    using namespace uiElements;
    using namespace managers;
    class MapSelectPromptScript : public GenericScript {
        public:
            MapSelectPromptScript(std::string name);
            void perform();
    };
}