
#include "MapSelectPromptInput.hpp"

using namespace components;

MapSelectPromptInput::MapSelectPromptInput(std::string name) :
    GenericInput(name),
    prevMap(false),
    nextMap(false){}

void MapSelectPromptInput::processKeyInput(sf::Keyboard::Key key, bool isPressed){
    switch(key){
        case sf::Keyboard::A:
        case sf::Keyboard::Left:
            this->prevMap = isPressed;
            this->nextMap = false;
            break;
        case sf::Keyboard::D:
        case sf::Keyboard::Right:
            this->prevMap = false;
            this->nextMap = isPressed;
            break;
        default:
            this->resetFlags();
    };
}

void MapSelectPromptInput::processMousePress(sf::Event::MouseButtonEvent buttonEvent, bool isPressed){}

bool MapSelectPromptInput::isGoPrev(){
    return this->prevMap;
}

bool MapSelectPromptInput::isGoNext(){
    return this->nextMap;
}

void MapSelectPromptInput::resetFlags(){
    this->prevMap = false;
    this->nextMap = false;
}
