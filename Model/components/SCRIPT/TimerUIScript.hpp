
#pragma once

#include "GenericScript.hpp"
#include "MatchTrackerScript.hpp"
#include "../../../Controller/managers/ObjectManager.hpp"
#include "../../systems/MatchTracker.hpp"
#include "../../uiElements/TimerUI.hpp"
#include "../../../Config/BalanceSettings.hpp"

namespace components {
    using namespace managers;
    using namespace systems;
    using namespace uiElements;
    class TimerUIScript : public GenericScript {
        public:
            TimerUIScript(std::string name);
            void perform();
    };
}