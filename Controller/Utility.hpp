
#pragma once

#include <iostream>

#include "../Model/entities/Entity.hpp"
#include "../Config/GameSettings.hpp"

namespace controllers {
    using namespace entities;
    class Utility {
        public:
            static int getRandomNumber(int lowerBound, int upperBound);
            static void setRandomLoc(Entity* refEntity);

        /* REMOVE INSTANTIATION */
        private:
            Utility();
            Utility(const Utility&);
            Utility& operator = (const Utility&);
    };
}