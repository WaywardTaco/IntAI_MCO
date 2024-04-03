
#include "ResultsPromptInput.hpp"

using namespace components;

ResultsPromptInput::ResultsPromptInput(std::string name) :
    GenericInput(name), escapePressed(false){}

void ResultsPromptInput::processKeyInput(sf::Keyboard::Key key, bool isPressed){
    switch(key){
        case sf::Keyboard::Escape:
            this->escapePressed = isPressed;
            break;
    }
}

void ResultsPromptInput::processMousePress(sf::Event::MouseButtonEvent buttonEvent, bool isPressed){}

bool ResultsPromptInput::isEscapePressed(){
    return this->escapePressed;
}

void ResultsPromptInput::resetEscapePress(){
    this->escapePressed = false;
}