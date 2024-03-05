
#pragma once

namespace components{
    class Component {
        public:
            Component(std::string name, ComponentType type);
            virtual void perform() = 0;


    };
}