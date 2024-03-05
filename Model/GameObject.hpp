
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
            bool enabled;

        public:
            std::vector<Component*> getComponents(ComponentType type);
            bool isEnabled();
    };
}