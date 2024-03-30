
#pragma once

#include "System.hpp"
#include "../components/SCRIPT/MatchTrackerScript.hpp"

namespace systems {
    using namespace components;
    class MatchTracker : public System {
        public:
            MatchTracker(std::string name);

            void initialize();
    };
}