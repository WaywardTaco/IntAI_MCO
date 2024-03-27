
#pragma once

#include "../../Config/GameSettings.hpp"
#include "../GameObject.hpp"
#include "../components/RENDERER/GenericRenderer.hpp"

namespace uiElements {
    using namespace components;
    using namespace models;
    class Background : public GameObject {
        public:
            Background(std::string name);
            void initialize();
    };
}