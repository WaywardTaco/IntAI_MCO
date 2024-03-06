
#pragma once

#include <iostream>
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include "../../Model/enums/TextureType.hpp"
#include "SceneManager.hpp"

namespace managers{
    class TextureManager{
        private:
            std::unordered_map<TextureType, std::unordered_map<std::string, std::string>> texturePaths;
            std::unordered_map<TextureType, std::vector<sf::Texture*>> loadedTextures;
        
        public:
            void loadTexture(TextureType type, std::string textureName);
            std::vector<sf::Texture*> getTexturesOf(TextureType type);
            sf::Texture* getTexture(TextureType type, unsigned int index);
            void unloadTextures();

        /* SINGLETON CODE */
        private:
            static TextureManager* SHARED_INSTANCE;
            TextureManager();
            TextureManager(const TextureManager&);
            TextureManager& operator = (const TextureManager&);
        public:
            TextureManager* Instance();
    };
}