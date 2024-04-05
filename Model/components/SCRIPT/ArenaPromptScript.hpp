#pragma once

#include "GenericScript.hpp"
#include "../INPUT/ArenaPromptInput.hpp"
#include "../../enums/SceneTag.hpp"
#include "../../../Controller/Game.hpp"
#include "../../../Controller/managers/SceneManager.hpp"
#include "../../uiElements/TextElement.hpp"

namespace components {
    using namespace controllers;
    using namespace managers;
    class ArenaPromptScript : public GenericScript {
        public:
            ArenaPromptScript(std::string name);
            void perform();
    };
}