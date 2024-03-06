
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>
#include <SFML/Graphics.hpp>

#include "Controller/managers/Settings.cpp"
#include "Controller/managers/SceneManager.cpp"
#include "Controller/managers/TextureManager.cpp"
#include "Controller/managers/ObjectManager.cpp"

#include "Model/enums/ComponentType.hpp"
#include "Model/enums/ObjectType.hpp"
#include "Model/enums/SceneTag.hpp"
#include "Model/enums/TextureType.hpp"

#include "View/AnimateTexture.cpp"

#include "Model/components/Component.cpp"
#include "Model/components/INPUT/GenericInput.cpp"
#include "Model/components/INPUT/MovementInput.cpp"
#include "Model/components/INPUT/PlayerShipMoveInput.cpp"
#include "Model/components/RENDERER/GenericRenderer.cpp"
#include "Model/components/SCRIPT/GenericScript.cpp"
#include "Model/components/SCRIPT/ShipMoveScript.cpp"

#include "Model/GameObject.cpp"

#include "Model/entities/Entity.cpp"
#include "Model/entities/Tank.cpp"
#include "Model/entities/Base.hpp"

#include "Model/uiElements/GenericButton.hpp"

#include "Model/scenes/Scene.cpp"
#include "Model/scenes/MainMenuScene.cpp"

#include "Controller/Game.cpp"

int main(){
    Game game;
    game.run();
    return 0;
}