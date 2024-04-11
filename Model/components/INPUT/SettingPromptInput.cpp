
#include "SettingPromptInput.hpp"

using namespace components;

SettingPromptInput::SettingPromptInput(std::string name) :
    GenericInput(name), spacePressed(false), escapePressed(false), leftPressed(false), rightPressed(false){}

void SettingPromptInput::processKeyInput(sf::Keyboard::Key key, bool isPressed){
    switch(key){
        case sf::Keyboard::Space:
            this->spacePressed = isPressed;
            break;
        case sf::Keyboard::Escape:
            this->escapePressed = isPressed;
            break;
        case sf::Keyboard::A:
        case sf::Keyboard::Left:
            this->leftPressed = isPressed;
            break;
        case sf::Keyboard::D:
        case sf::Keyboard::Right:
            this->rightPressed = isPressed;
            break;
    }
}

void SettingPromptInput::processMousePress(sf::Event::MouseButtonEvent buttonEvent, bool isPressed){

}

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

bool SettingPromptInput::isLeftPressed(){
    return this->leftPressed;
}

void SettingPromptInput::resetLeftPressed(){
    this->leftPressed = false;
}

bool SettingPromptInput::isRightPressed(){
    return this->rightPressed;
}

void SettingPromptInput::resetRightPressed(){
    this->rightPressed = false;
}
