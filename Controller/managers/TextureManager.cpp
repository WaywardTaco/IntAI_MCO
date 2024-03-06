
#include "TextureManager.hpp"

using namespace managers;

TextureManager::TextureManager(){
    texturePaths[TextureType::TANK_ROLL_RIGHT]["Frame1"] = "View/Images/Tank/Roll/Tank_Roll_Right_Frame1.png";
    texturePaths[TextureType::TANK_ROLL_RIGHT]["Frame2"] = "View/Images/Tank/Roll/Tank_Roll_Right_Frame2.png";
    texturePaths[TextureType::TANK_ROLL_RIGHT]["Frame3"] = "View/Images/Tank/Roll/Tank_Roll_Right_Frame3.png";
    texturePaths[TextureType::TANK_ROLL_RIGHT]["Frame4"] = "View/Images/Tank/Roll/Tank_Roll_Right_Frame4.png";
}

void TextureManager::loadTexture(TextureType type, std::string textureName){
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

std::vector<sf::Texture*> TextureManager::getTexturesOf(TextureType type){
    if(this->loadedTextures[type].size() <= 0){
        std::cout << "Textures not loaded" << std::endl;
        return {};
    }

    return this->loadedTextures[type];
}

sf::Texture* TextureManager::getTexture(TextureType type, unsigned int index = 0){
    if(index >= this->loadedTextures[type].size())
        return NULL;

    return this->loadedTextures[type][index];
}

void TextureManager::unloadTextures(){
    for(std::unordered_map<TextureType, std::vector<sf::Texture*>>::iterator itr = loadedTextures.begin(); itr != loadedTextures.end(); itr++){
        for(sf::Texture* texture : itr->second){
            delete texture;
        }

        itr->second.clear();
    }
}

/* SINGLETON CODE */
TextureManager* TextureManager::SHARED_INSTANCE = NULL;
TextureManager::TextureManager(const TextureManager&){};
TextureManager* TextureManager::Instance(){
    if(SHARED_INSTANCE == NULL)
        SHARED_INSTANCE = new TextureManager();

    return SHARED_INSTANCE;
}