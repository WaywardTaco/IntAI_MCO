
#include "GenericRenderer.hpp"

using namespace components;

GenericRenderer::GenericRenderer(std::string name) :
    Component(name, ComponentType::RENDERER),
    drawables({}),
    window(NULL){}

void GenericRenderer::perform(){
    for(sf::Drawable* drawable : this->drawables)
        this->window->draw(*drawable);
}

void GenericRenderer::assignWindow(sf::RenderWindow* window){
    this->window = window;
}

void GenericRenderer::assignDrawable(sf::Drawable* drawable){
    this->drawables.push_back(drawable);
}
 