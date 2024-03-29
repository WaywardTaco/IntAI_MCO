
#include "TextureManager.hpp"

using namespace managers;

TextureManager::TextureManager(){
    texturePaths[TextureType::ASTEROID]["Frame1"] = "View/Images/Asteroid/Asteroid.PNG" ;
    texturePaths[TextureType::BACKGROUND]["StartMenu"] = "View/Images/Background/SpaceMainMenu.png";
    texturePaths[TextureType::BACKGROUND]["MainMenu"] = "View/Images/Background/SpaceBG.png";
    texturePaths[TextureType::BASE]["Normal"] = "View/Images/Base/Base_Normal.PNG" ;
    texturePaths[TextureType::BASE]["Ruined"] = "View/Images/Base/Base_Ruined.PNG" ;
    texturePaths[TextureType::BASE]["Shielded"] = "View/Images/Base/Base_Shielded.PNG" ;
    texturePaths[TextureType::BULLET]["Frame1"] = "View/Images/Tank/Roll/Tank_Roll_Right_Frame4.png";
    texturePaths[TextureType::POWERUP]["Chaos"] = "View/Images/Powerup/Powerup_Chaos.PNG" ;
    texturePaths[TextureType::POWERUP]["Mine"] = "View/Images/Powerup/Powerup_Mine.PNG" ;
    texturePaths[TextureType::POWERUP]["Shield"] = "View/Images/Powerup/Powerup_Shield.PNG" ;
    texturePaths[TextureType::SHIP]["Basic"] = "View/Images/Ship/Ship_Basic.PNG" ;
    texturePaths[TextureType::SHIP]["Gunner"] = "View/Images/Ship/Ship_Basic.PNG" ;
    texturePaths[TextureType::SHIP]["Intercepter"] = "View/Images/Ship/Ship_Intercepter.PNG" ;
    texturePaths[TextureType::SHIP]["Tanker"] = "View/Images/Ship/Ship_Tanker.PNG" ;

    texturePaths[TextureType::TANK_ROLL_RIGHT]["Frame1"] = "View/Images/Ship/shipNoBG.png";
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

void TextureManager::unloadTextures(){
    for(std::unordered_map<TextureType, std::vector<sf::Texture*>>::iterator itr = loadedTextures.begin(); itr != loadedTextures.end(); itr++){
        for(sf::Texture* texture : itr->second)
            delete texture;

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