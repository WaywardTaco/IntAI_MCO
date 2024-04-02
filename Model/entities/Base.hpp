
#pragma once

#include "TeamMember.hpp"
#include "../../Config/BalanceSettings.hpp"
#include "../components/SCRIPT/MatchTrackerScript.hpp"
#include "../components/SCRIPT/BaseCaptureScript.hpp"

namespace entities {
    class Base : public TeamMember {
        public:
            Base(std::string name, ObjectTeams team);

            void initialize();
            void kill();
            void startShield();
    };
}