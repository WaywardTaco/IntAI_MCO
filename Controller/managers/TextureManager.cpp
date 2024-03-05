
#include "TextureManager.hpp"

using namespace managers;

SceneManager::SceneManager(){
    texturePaths[TextureType::PLAYER]["NAME"] = "NAME";
}

void SceneManager::loadTexture(TextureType type, std::string textureName){
    if(this->texturePaths[type][textureName].empty()){
        std::cout << "No texture of that type" << std::endl;
        return;
    }

    sf::Texture* texture = new sf::Texture;
    if(!texture->loadFromFile(this->texturePaths[type][textureName])){
        std::cout << "Failed to load texture at Path: " << this->texturePaths[type][textureName] << std::endl;
        return;
    }

    this->loadedTextures[type].push_back(texture);
}

std::vector<sf::Texture*> SceneManager::getTexturesOf(TextureType type){
    if(this->loadedTextures[type].size() <= 0){
        std::cout << "Textures not loaded" << std::endl;
        return {};
    }

    return this->loadedTextures[type];
}

sf::Texture* SceneManager::getTexture(TextureType type, unsigned int index = 0){
    if(index >= this->loadedTextures[type].size())
        return NULL;

    return this->loadedTextures[type][index];
}

void SceneManager::unloadTextures(){
    for(std::unordered_map<TextureType, std::vector<sf::Texture*>>::iterator itr = loadedTextures.begin(); itr != loadedTextures.end(); itr++){
        for(sf::Texture* texture : itr->second){
            delete texture;
        }

        itr->second.clear();
    }
}

/* SINGLETON CODE */
SceneManager* SceneManager::SHARED_INSTANCE = NULL;
SceneManager::SceneManager(const SceneManager&){};
SceneManager* SceneManager::Instance(){
    if(SHARED_INSTANCE == NULL)
        SHARED_INSTANCE = new SceneManager();

    return SHARED_INSTANCE;
}