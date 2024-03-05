
#pragma once

#include <iostream>
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include "../../Model/enums/TextureType.hpp"

namespace managers{
    class SceneManager{
        private:
            std::unordered_map<TextureType, std::unordered_map<std::string, std::string>> texturePaths;
            std::unordered_map<TextureType, std::vector<sf::Texture*>> loadedTextures;
        
        public:
            void loadTexture(TextureType type, std::string textureName);
            std::vector<sf::Texture*> getTexturesOf(TextureType type);
            sf::Texture* getTexture(TextureType type, unsigned int index = 0);
            void unloadTextures();

        /* SINGLETON CODE */
        private:
            static SceneManager* SHARED_INSTANCE;
            SceneManager();
            SceneManager(const SceneManager&);
            SceneManager& operator = (const SceneManager&);
        public:
            SceneManager* Instance();
    };
}