#pragma once

#include "GenericScript.hpp"
#include "../INPUT/SettingPromptInput.hpp"
#include "../../enums/SceneTag.hpp"
#include "../../../Controller/Game.hpp"
#include "../../../Controller/managers/SceneManager.hpp"
#include "../../uiElements/TextElement.hpp"

namespace components {
    using namespace controllers;
    using namespace managers;
    class SettingPromptScript : public GenericScript {
        public:
            SettingPromptScript(std::string name);
            void perform();
    };
}