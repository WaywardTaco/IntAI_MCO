#pragma once

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

namespace managers{
    class ControlManager{
        private:
            sf::Keyboard::Key up;
            sf::Keyboard::Key down;
            sf::Keyboard::Key left;
            sf::Keyboard::Key right;
            int count;

        public:
            void setControlScheme();

        private:
            static ControlManager* P_SHARED_INSTANCE;
            ControlManager();
            ControlManager(const ControlManager&);
            ControlManager& operator = (const ControlManager&);

        public:
            static ControlManager* getInstance();
            sf::Keyboard::Key getUp();
            sf::Keyboard::Key getDown();
            sf::Keyboard::Key getLeft();
            sf::Keyboard::Key getRight();

    };
}