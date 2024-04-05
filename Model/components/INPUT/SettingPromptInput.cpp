
#include "SettingPromptInput.hpp"

using namespace components;

SettingPromptInput::SettingPromptInput(std::string name) :
    GenericInput(name), spacePressed(false), escapePressed(false){}

void SettingPromptInput::processKeyInput(sf::Keyboard::Key key, bool isPressed){
    switch(key){
        case sf::Keyboard::Space:
            this->spacePressed = isPressed;
            break;
        case sf::Keyboard::Escape:
            this->escapePressed = isPressed;
            break;

    }
}

void SettingPromptInput::processMousePress(sf::Event::MouseButtonEvent buttonEvent, bool isPressed){}

bool SettingPromptInput::isSpacePressed(){
    return this->spacePressed;
}

void SettingPromptInput::resetSpacePressed(){
    this->spacePressed = false;
}

bool SettingPromptInput::isEscapePressed(){
    return this->escapePressed;
}

void SettingPromptInput::resetEscapePressed(){
    this->escapePressed = false;
}
