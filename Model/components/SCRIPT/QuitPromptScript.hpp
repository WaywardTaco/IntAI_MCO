#pragma once

#include "GenericScript.hpp"
#include "../INPUT/QuitPromptInput.hpp"
#include "../../enums/SceneTag.hpp"
#include "../../../Controller/Game.hpp"
#include "../../../Controller/managers/SceneManager.hpp"
#include "../../uiElements/TextElement.hpp"

namespace components {
    using namespace controllers;
    using namespace managers;
    class QuitPromptScript : public GenericScript {
        public:
            QuitPromptScript(std::string name);
            void perform();
    };
}