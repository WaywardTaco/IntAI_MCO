#pragma once

#include "GenericScript.hpp"
#include "../INPUT/SettingPromptInput.hpp"
#include "../../enums/SceneTag.hpp"
#include "../../../Controller/Game.hpp"
#include "../../../Controller/managers/SceneManager.hpp"
#include "../../../Controller/managers/ControlManager.hpp"
#include "../../uiElements/TextElement.hpp"

namespace scenes{
    class SettingsScene;
}

namespace components {
    using namespace controllers;
    using namespace managers;
    class SettingPromptScript : public GenericScript {
        private:
            int count;

        public:
            SettingPromptScript(std::string name);
            void perform();
    };
}