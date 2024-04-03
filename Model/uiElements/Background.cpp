
#include "Background.hpp"

using namespace uiElements;

Background::Background(std::string name) :
    GameObject(name, ObjectType::BACKGROUND)
{
    this->setTexture(new AnimateTexture(TextureManager::Instance()->getTexturesOf(TextureType::BACKGROUND)));
}

void Background::initialize(){

    GenericRenderer* renderer = new GenericRenderer(this->getName() + "Renderer");
    renderer->assignDrawable(this->getSprite());
    this->attachComponent(renderer);
    
    this->getSprite()->setScale(
        WINDOW_WIDTH / this->sprite->getLocalBounds().width, 
        WINDOW_HEIGHT / this->sprite->getLocalBounds().height
    );
    this->getSprite()->setColor(
        sf::Color(100, 100, 100)
    );
}