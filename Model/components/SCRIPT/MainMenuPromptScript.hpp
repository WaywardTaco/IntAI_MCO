
#pragma once

#include "GenericScript.hpp"
#include "../INPUT/MainMenuPromptInput.hpp"
#include "../../enums/SceneTag.hpp"
#include "../../../Controller/Game.hpp"
#include "../../../Controller/managers/SceneManager.hpp"

namespace components {
    using namespace controllers;
    using namespace managers;
    class MainMenuPromptScript : public GenericScript {
        public:
            MainMenuPromptScript(std::string name);
            void perform();
    };
}