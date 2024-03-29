
#pragma once

#include "TeamMember.hpp"
#include "../../Config/BalanceSettings.hpp"

namespace entities {
    class Base : public TeamMember {
        public:
            Base(std::string name, ObjectTeams team);

            void initialize();
            void kill();
    };
}