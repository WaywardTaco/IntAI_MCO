
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
    }
}

void GenericInput::assignEvent(sf::Event event){
    this->event = event;
}
