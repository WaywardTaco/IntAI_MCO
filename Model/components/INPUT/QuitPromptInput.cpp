
#include "QuitPromptInput.hpp"

using namespace components;

QuitPromptInput::QuitPromptInput(std::string name) :
    GenericInput(name), spacePressed(false), escapePressed(false){}

void QuitPromptInput::processKeyInput(sf::Keyboard::Key key, bool isPressed){
    switch(key){
        case sf::Keyboard::Space:
            this->spacePressed = isPressed;
            break;
        case sf::Keyboard::Escape:
            this->escapePressed = isPressed;
            break;

    }
}

void QuitPromptInput::processMousePress(sf::Event::MouseButtonEvent buttonEvent, bool isPressed){}

bool QuitPromptInput::isSpacePressed(){
    return this->spacePressed;
}

void QuitPromptInput::resetSpacePressed(){
    this->spacePressed = false;
}

bool QuitPromptInput::isEscapePressed(){
    return this->escapePressed;
}

void QuitPromptInput::resetEscapePressed(){
    this->escapePressed = false;
}
