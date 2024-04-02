
#include "TextElement.hpp"

using namespace uiElements;

TextElement::TextElement(std::string name, std::string text, sf::Font* font, int fontSize, ObjectType type) : 
    GameObject(name, type)
{
    this->sfText = new sf::Text();
    this->sfText->setFont(*font);
    this->sfText->setCharacterSize(fontSize);
    this->setText(text, false);
}

void TextElement::initialize(){
    GenericRenderer* renderer = new GenericRenderer(this->getName() + "Renderer");
    renderer->assignDrawable(this->sfText);
    this->attachComponent(renderer);
}

void TextElement::setText(std::string text, bool centerOrigin){
    this->sfText->setString(text);
    if(centerOrigin)
        this->sfText->setOrigin(this->sfText->getGlobalBounds().width / 2.f, this->sfText->getGlobalBounds().height / 2.f);
}

void TextElement::setPosition(sf::Vector2f position){
    this->position = position;
    this->sfText->setPosition(position);
}