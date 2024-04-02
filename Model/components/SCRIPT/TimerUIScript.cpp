
#include "TimerUIScript.hpp"

using namespace components;

TimerUIScript::TimerUIScript(std::string name) :
    GenericScript(name){}

void TimerUIScript::perform(){
    MatchTracker* match = (MatchTracker*) ObjectManager::Instance()->findObjectByName("MatchTracker");
    if(match == NULL){
        std::cout << "Missing Dependency!" << std::endl;
        return;
    }
    MatchTrackerScript* tracker = (MatchTrackerScript*) match->getComponent(match->getName() + "Script");
    TimerUI* owner = (TimerUI*) this->getOwner();

    if(tracker == NULL || owner == NULL){
        std::cout << "Dependency Missing!" << std::endl;
        return;
    } 

    int 
        timeLeft = MATCH_SECONDS - tracker->getMatchTime(),
        minutesLeft = timeLeft / 60,
        secondsLeft = timeLeft - (minutesLeft * 60);

    if(secondsLeft <= 0)
        owner->setText("Timer: " + std::to_string(minutesLeft) + ":00", false);
    else if(secondsLeft < 10)
        owner->setText("Timer: " + std::to_string(minutesLeft) + ":0" + std::to_string(secondsLeft), false);
    else
        owner->setText("Timer: " + std::to_string(minutesLeft) + ":" + std::to_string(secondsLeft), false);
}