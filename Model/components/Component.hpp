
#pragma once

#include <string>
#include "../GameObject.hpp"

namespace components{
    using namespace models;
    class Component {
        protected:
            GameObject* owner;
            ComponentType type;
            std::string name;

        public:
            Component(std::string name, ComponentType type);
            virtual ~Component();

            virtual void perform() = 0;

            void attachOwner(GameObject* owner);
            void detachOwner();

            GameObject* getOwner();
            ComponentType getType();
            std::string getName();
    };
}