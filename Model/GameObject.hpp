
#pragma once

#include <unordered_map>
#include <vector>
#include "enums/ComponentType.hpp"
#include "components/Component.hpp"

namespace models {
    using namespace components;
    class GameObject{
        private:
            std::unordered_map<ComponentType, std::vector<Component*>> mapComponents;

            std::string name;
            bool enabled;

        public:
            virtual void initialize() = 0;

            std::vector<Component*> getComponents(ComponentType type);
            std::string getName();
            bool isEnabled();
    };
}