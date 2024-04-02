
#pragma once

#include "../../../Config/BalanceSettings.hpp"
#include "GenericScript.hpp"
#include "../COLLIDER/ColliderBase.hpp"
#include "../../entities/Base.hpp"
#include "../../entities/Ship.hpp"

namespace components {
    using namespace entities;

    class BaseCaptureScript : public GenericScript {
        private:
            float
                shieldTime, 
                captureTime;
            bool shielded;
        
        public:
            BaseCaptureScript(std::string name);
            void perform();
            void startShield();
    };
}