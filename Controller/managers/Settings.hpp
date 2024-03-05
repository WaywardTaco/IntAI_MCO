
#pragma once

#include <SFML/Graphics.hpp>

namespace managers{
    class Settings{
        private:
            sf::VideoMode windowDim;
            sf::Time frameTime;

        public:
            void setWindowDim(int height, int width);
            sf::VideoMode getWindowDim();
            void setWindowName(std::string name);
            std::string getWindowName();
            void setFrameTime(sf::Time time);
            sf::Time getFrameTime();

        /* SINGLETON CODE */
        private:
            static Settings* SHARED_INSTANCE;
            Settings();
            Settings(const Settings&);
            Settings& operator = (const Settings&);
        public:
            static Settings* Instance();
    };
}