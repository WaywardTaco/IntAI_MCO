
#include "System.hpp"

using namespace systems;

System::System(std::string name, ObjectType type) :
    GameObject(name, type){}

GameObject* System::copy(){
    return this;
}