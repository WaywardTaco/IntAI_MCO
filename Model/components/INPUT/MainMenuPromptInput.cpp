
#include "MainMenuPromptInput.hpp"

using namespace components;

MainMenuPromptInput::MainMenuPromptInput(std::string name) :
    GenericInput(name), spacePressed(false), escapePressed(false), enterPressed(false){}

void MainMenuPromptInput::processKeyInput(sf::Keyboard::Key key, bool isPressed){
    switch(key){
        case sf::Keyboard::Space:
            this->spacePressed = isPressed;
            break;
        case sf::Keyboard::Escape:
            this->escapePressed = isPressed;
            break;
        case sf::Keyboard::Enter:
            this->enterPressed = isPressed;

    }
}

void MainMenuPromptInput::processMousePress(sf::Event::MouseButtonEvent buttonEvent, bool isPressed){}

bool MainMenuPromptInput::isSpacePressed(){
    return this->spacePressed;
}

void MainMenuPromptInput::resetSpacePressed(){
    this->spacePressed = false;
}

bool MainMenuPromptInput::isEscapePressed(){
    return this->escapePressed;
}

void MainMenuPromptInput::resetEscapePressed(){
    this->escapePressed = false;
}
bool MainMenuPromptInput::isEnterPressed(){
    return this->enterPressed;
}

void MainMenuPromptInput::resetEnterPressed(){
    this->enterPressed = false;
}