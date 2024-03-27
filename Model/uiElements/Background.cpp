
#include "Background.hpp"

using namespace uiElements;

Background::Background(std::string name) :
    GameObject(name, ObjectType::BACKGROUND)
{
    this->setTexture(new AnimateTexture(TextureManager::Instance()->getTexturesOf(TextureType::BACKGROUND)));
    this->sprite->setScale(
        WINDOW_WIDTH / this->sprite->getTexture()->getSize().x, 
        WINDOW_HEIGHT / this->sprite->getTexture()->getSize().y);
}

void Background::initialize(){

    GenericRenderer* renderer = new GenericRenderer(this->getName() + "Renderer");
    renderer->assignDrawable(this->getSprite());
    this->attachComponent(renderer);
    
}