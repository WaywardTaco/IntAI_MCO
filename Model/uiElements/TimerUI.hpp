
#pragma once

#include "TextElement.hpp"
#include "../components/SCRIPT/TimerUIScript.hpp"
#include "../../Config/GameSettings.hpp"

namespace uiElements {
    using namespace components;
    class TimerUI : public TextElement {
        public:
            TimerUI(std::string name, sf::Font* font);
            void initialize();
    };
}