
#include "ArenaPromptInput.hpp"

using namespace components;

ArenaPromptInput::ArenaPromptInput(std::string name) :
    GenericInput(name), escapePressed(false){}

void ArenaPromptInput::processKeyInput(sf::Keyboard::Key key, bool isPressed){
    switch(key){
        case sf::Keyboard::Escape:
            this->escapePressed = isPressed;
            break;
    }
}

void ArenaPromptInput::processMousePress(sf::Event::MouseButtonEvent buttonEvent, bool isPressed){}


bool ArenaPromptInput::isEscapePressed(){
    return this->escapePressed;
}

void ArenaPromptInput::resetEscapePressed(){
    this->escapePressed = false;
}