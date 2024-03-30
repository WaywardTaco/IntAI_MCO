
#include "MatchTracker.hpp"

using namespace systems;

MatchTracker::MatchTracker(std::string name) :
    System(name, ObjectType::MATCH_TRACKER){};

void MatchTracker::initialize(){
    this->attachComponent(new MatchTrackerScript(this->getName() + "Script"));
}