
#include "AnimateTexture.hpp"

using namespace view;

AnimateTexture::AnimateTexture(std::vector<sf::Texture*> frames) : 
    frames(frames), currFrame(0) {}

void AnimateTexture::nextFrame(){
    this->currFrame = (this->currFrame + 1) % this->frames.size();
}

void AnimateTexture::setFrame(int frame){
    if(frame < 0 || frame >= this->frames.size())
        this->currFrame = this->frames.size() - 1;
    else    
        this->currFrame = (unsigned int) frame;
}

sf::Texture* AnimateTexture::getFrame(){
    return this->frames[this->currFrame];
}

sf::Texture* AnimateTexture::getFrameAt(int frame){
    if(frame < 0 || frame >= this->frames.size())
        return this->frames[this->frames.size() - 1];
    
    return this->frames[frame];
}

unsigned int AnimateTexture::getFrameCount(){
    return this->frames.size();
}

unsigned int AnimateTexture::getCurrFrame(){
    return this->currFrame;
}