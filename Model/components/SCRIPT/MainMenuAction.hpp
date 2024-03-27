#pragma once

#include "../../../Controller/Manager/SceneManager.hpp"
#include "../../Enum/ComponentType.hpp"
#include "../../Enum/SceneTag.hpp"
#include "../Component.hpp"
#include "../Input/BackgroundInput.hpp"

namespace components {
    using namespace managers;

    class MainMenuAction : public Component {
        public:
            MainMenuAction(std::string strName);

        public:
            void perform();
    };
}
