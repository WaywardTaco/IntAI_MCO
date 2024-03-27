
#include "AnimateTexture.hpp"

using namespace view;

AnimateTexture::AnimateTexture(std::vector<sf::Texture*> frames) : 
    frames(frames), 
    currentFrameIndex(0),
    animationStartFrameIndex(0),
    animationEndFrameIndex(frames.size() - 1){}

void AnimateTexture::iterateFrames(){
    this->currentFrameIndex = 
        (this->currentFrameIndex - this->animationStartFrameIndex + 1) 
        % (this->animationEndFrameIndex - this->animationStartFrameIndex + 1) 
        + this->animationStartFrameIndex;
}

void AnimateTexture::setFrame(int index){
    if(index - this->animationStartFrameIndex < 0)
        this->currentFrameIndex = this->animationStartFrameIndex;
    else if (index + this->animationStartFrameIndex > this->animationEndFrameIndex)
        this->currentFrameIndex = this->animationEndFrameIndex;
    else
        this->currentFrameIndex = index + this->animationStartFrameIndex;
}

sf::Texture* AnimateTexture::getFrame(){
    return this->frames[this->currentFrameIndex];
}

void AnimateTexture::setAnimationLimits(unsigned int startIndex, unsigned int endIndex){
    if(startIndex > endIndex){
        std::cout << "Undefined behavior, animation indecies inconsistent" << std::endl;
        return;
    }

    if(endIndex > this->frames.size() - 1)
        endIndex = this->frames.size() - 1;
    
    this->animationStartFrameIndex = startIndex;
    this->animationEndFrameIndex = endIndex;
}

