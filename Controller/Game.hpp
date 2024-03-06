
#pragma once

#include <SFML/Graphics.hpp>
#include "../Model/enums/SceneTag.hpp"
#include "managers/Settings.hpp"
#include "managers/ObjectManager.hpp"
#include "managers/SceneManager.hpp"

namespace controllers{
    using namespace managers;
    class Game {
        private:
            sf::RenderWindow window;
            bool windowToClose;

        public:
            Game();
        
            void run();
        
        private:
            void processEvents();
            void update();
            void render();
    };
}