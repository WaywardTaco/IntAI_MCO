
#pragma once

#include <SFML/Graphics.hpp>
#include "../Config/GameSettings.hpp"
#include "../Model/enums/SceneTag.hpp"
#include "managers/ObjectManager.hpp"
#include "managers/SceneManager.hpp"
#include "managers/ColliderManager.hpp"
#include "../Model/scenes/MainMenuScene.hpp"
#include "../Model/scenes/ArenaScene.hpp"
#include "../Model/scenes/ResultsScene.hpp"

namespace controllers{
    using namespace managers;
    using namespace scenes;
    class Game {
        private:
            sf::RenderWindow window;
            bool windowToClose;

        public:
            void run();

            void close();
        
        private:
            void processEvents();
            void update();
            void render();

        /* SINGLETON CODE */
        private:
            static Game* SHARED_INSTANCE;
            Game();
            Game(const Game&);
            Game& operator = (const Game&);
        public:
            static Game* Instance();
    };
}