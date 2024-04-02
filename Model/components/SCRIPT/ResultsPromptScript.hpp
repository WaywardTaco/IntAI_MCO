
#pragma once

#include "GenericScript.hpp"
#include "../INPUT/ResultsPromptInput.hpp"
#include "../../enums/SceneTag.hpp"
#include "../../../Controller/managers/SceneManager.hpp"

namespace components {
    using namespace managers;
    class ResultsPromptScript : public GenericScript {
        public:
            ResultsPromptScript(std::string name);
            void perform();
    };
}