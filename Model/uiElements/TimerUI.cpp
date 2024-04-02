
#include "TimerUI.hpp"

using namespace uiElements;

TimerUI::TimerUI(std::string name, sf::Font* font) :
    TextElement(name, "Timer: 2:00", font, TIMER_FONT_SIZE, ObjectType::TIMER_UI){}

void TimerUI::initialize(){
    this->attachComponent(new TimerUIScript(this->getName() + "Script"));
    TextElement::initialize();
}