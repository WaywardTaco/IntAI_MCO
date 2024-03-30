
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>
#include <SFML/Graphics.hpp>

#include "Config/GameSettings.hpp"
#include "Config/BalanceSettings.hpp"
#include "Config/ControlSettings.hpp"
#include "Controller/Utility.cpp"

#include "Controller/managers/SceneManager.cpp"
#include "Controller/managers/TextureManager.cpp"
#include "Controller/managers/ObjectManager.cpp"
#include "Controller/managers/ObjectPoolManager.cpp"
#include "Controller/managers/ColliderManager.cpp"

#include "Model/enums/ComponentType.hpp"
#include "Model/enums/ObjectType.hpp"
#include "Model/enums/SceneTag.hpp"
#include "Model/enums/TextureType.hpp"

#include "View/AnimateTexture.cpp"

#include "Model/components/Component.cpp"
#include "Model/components/INPUT/GenericInput.cpp"
#include "Model/components/INPUT/PlayerInput.cpp"
#include "Model/components/COLLIDER/ColliderBase.cpp"
#include "Model/components/RENDERER/GenericRenderer.cpp"
#include "Model/components/SCRIPT/GenericScript.cpp"
#include "Model/components/SCRIPT/PlayerShipActions.cpp"
#include "Model/components/SCRIPT/BulletMoveScript.cpp"
#include "Model/components/SCRIPT/PowerupScript.cpp"
#include "Model/components/SCRIPT/SpawnerScript.cpp"
#include "Model/components/SCRIPT/MatchTrackerScript.cpp"

#include "Model/GameObject.cpp"
#include "Model/ObjectPool.cpp"

#include "Model/entities/Entity.cpp"
#include "Model/entities/Powerup.cpp"

#include "Model/entities/TeamMember.cpp"
#include "Model/entities/Ship.cpp"
#include "Model/entities/PlayerShip.cpp"
#include "Model/entities/EnemyShip.cpp"
#include "Model/entities/Bullet.cpp"
#include "Model/entities/Base.cpp"

#include "Model/systems/System.cpp"
#include "Model/systems/Spawner.cpp"
#include "Model/systems/MatchTracker.cpp"

#include "Model/uiElements/GenericButton.hpp"
#include "Model/uiElements/Background.cpp"

#include "Model/scenes/Scene.cpp"
#include "Model/scenes/MainMenuScene.cpp"
#include "Model/scenes/ArenaScene.cpp"

#include "Controller/Game.cpp"

/***********************************************/

int main(){
    Game::Instance()->run();
    return 0;
}