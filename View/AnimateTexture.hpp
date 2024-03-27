
#pragma once

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

namespace view {
    class AnimateTexture {
        private:
            std::vector<sf::Texture*> frames;
            unsigned int 
                currentFrameIndex,
                animationStartFrameIndex,
                animationEndFrameIndex;

        public:
            AnimateTexture(std::vector<sf::Texture*> frames);
            
            void iterateFrames();
            sf::Texture* getFrame();
            void setFrame(int index);

            void setAnimationLimits(unsigned int startFrame, unsigned int endFrame);
    };
}