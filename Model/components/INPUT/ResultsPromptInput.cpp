
#include "ResultsPromptInput.hpp"

using namespace components;

ResultsPromptInput::ResultsPromptInput(std::string name) :
    GenericInput(name), spacePressed(false){}

void ResultsPromptInput::processKeyInput(sf::Keyboard::Key key, bool isPressed){
    switch(key){
        case sf::Keyboard::Space:
            this->spacePressed = isPressed;
            break;
    }
}

void ResultsPromptInput::processMousePress(sf::Event::MouseButtonEvent buttonEvent, bool isPressed){}

bool ResultsPromptInput::isSpacePressed(){
    return this->spacePressed;
}

void ResultsPromptInput::resetSpacePressed(){
    this->spacePressed = false;
}