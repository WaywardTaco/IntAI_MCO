
#pragma once

#include "GenericScript.hpp"
#include "MatchTrackerScript.hpp"
#include "../../uiElements/ScoreUI.hpp"
#include "../../systems/MatchTracker.hpp"
#include "../../../Controller/managers/ObjectManager.hpp"

namespace components {
    using namespace uiElements;
    using namespace managers;
    using namespace systems;
    class ScoreUIScript : public GenericScript {
        public:
            ScoreUIScript(std::string name);
            void perform();
    };
}