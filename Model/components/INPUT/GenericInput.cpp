
#include "GenericInput.hpp"

using namespace components;

GenericInput::GenericInput(std::string name) :
    Component(name, ComponentType::INPUT){}

void GenericInput::perform(){
    switch(this->event.type){
        case sf::Event::KeyPressed:
            this->processKeyInput(event.key.code, true);
            break;
        case sf::Event::KeyReleased:
            this->processKeyInput(event.key.code, false);
            break;
        case sf::Event::MouseButtonPressed:
            processMousePress(event.mouseButton, true);
            break;
        case sf::Event::MouseButtonReleased:
            processMousePress(event.mouseButton, false);
            break;
        case sf::Event::MouseMoved:
            this->vecLocation.x = this->event.mouseMove.x;
            this->vecLocation.y = this->event.mouseMove.y;
            break;
    }
}

void GenericInput::assignEvent(sf::Event event){
    this->event = event;
}
