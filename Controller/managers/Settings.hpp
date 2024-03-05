
#pragma once

#include <string>
#include <SFML/Graphics.hpp>

namespace managers{
    class Settings{
        private:
            sf::VideoMode windowDim;
            std::string windowName;
            sf::Time frameTime;
            float frameLimit;

        public:
            void setWindowDim(unsigned int height, unsigned int width);
            sf::VideoMode getWindowDim();
            void setWindowName(std::string name);
            std::string getWindowName();
            void setFrameTime(sf::Time time);
            sf::Time getFrameTime();
            void setFrameLimit(float limit);
            float getFrameLimit();

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