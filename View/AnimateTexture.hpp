
#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

namespace view {
    class AnimateTexture {
        private:
            std::vector<sf::Texture*> frames;
            unsigned int currFrame;

        public:
            AnimateTexture(std::vector<sf::Texture*> frames);

            void nextFrame();
            void setFrame(int frame);
            sf::Texture* getFrame();
            sf::Texture* getFrameAt(int frame);
            unsigned int getFrameCount();
            unsigned int getCurrFrame();
    };
}