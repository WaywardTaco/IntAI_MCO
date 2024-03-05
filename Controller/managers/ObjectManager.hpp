
#pragma once

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "../../Model/enums/ObjectType.hpp"
#include "../../Model/enums/ComponentType.hpp"
#include "../../Model/GameObject.hpp"
#include "../../Model/components/Component.hpp"
#include "../../Model/components/INPUT/GenericInput.hpp"
#include "../../Model/components/SCRIPT/GenericScript.hpp"
#include "../../Model/components/RENDERER/GenericRenderer.hpp"

namespace managers{
    using namespace models;
    using namespace components;
    class ObjectManager{
        private:
            std::unordered_map<std::string, GameObject*> mapObjects;
            std::vector<GameObject*> vecObjects;
        
        public:
            void processEvents(sf::Event event);
            void update(sf::Time deltaTime);
            void draw(sf::RenderWindow* window);

            void addObject(GameObject* object);
            GameObject* findObjectByName(std::string name);
            std::vector<GameObject*> getObjects(ObjectType type);
            void deleteAllObjects();

        /* SINGLETON CODE */
        private:
            static ObjectManager* SHARED_INSTANCE;
            ObjectManager();
            ObjectManager(const ObjectManager&);
            ObjectManager& operator = (const ObjectManager&);
        public:
            static ObjectManager* Instance();
    };
}