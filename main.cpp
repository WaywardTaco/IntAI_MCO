
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

#include "Controller/managers/AudioManager.cpp"
#include "Controller/managers/SceneManager.cpp"
#include "Controller/managers/TextureManager.cpp"
#include "Controller/managers/ObjectManager.cpp"
#include "Controller/managers/ObjectPoolManager.cpp"
#include "Controller/managers/ColliderManager.cpp"

#include "Model/enums/ComponentType.hpp"
#include "Model/enums/FacingDir.hpp"
#include "Model/enums/MapTypes.hpp"
#include "Model/enums/ObjectTeams.hpp"
#include "Model/enums/ObjectType.hpp"
#include "Model/enums/PowerupType.hpp"
#include "Model/enums/SceneTag.hpp"
#include "Model/enums/TextureType.hpp"
#include "Model/enums/SoundType.hpp"
#include "Model/enums/MusicType.hpp"

#include "View/AnimateTexture.cpp"

#include "Model/components/Component.cpp"
#include "Model/components/AUTOMATION/EnemyAI.cpp"
#include "Model/components/INPUT/GenericInput.cpp"
#include "Model/components/INPUT/PlayerInput.cpp"
#include "Model/components/INPUT/MainMenuPromptInput.cpp"
#include "Model/components/INPUT/MapSelectPromptInput.cpp"
#include "Model/components/INPUT/ResultsPromptInput.cpp"
#include "Model/components/INPUT/QuitPromptInput.cpp"
#include "Model/components/INPUT/SettingPromptInput.cpp"
#include "Model/components/INPUT/ArenaPromptInput.cpp"
#include "Model/components/COLLIDER/ColliderBase.cpp"
#include "Model/components/RENDERER/GenericRenderer.cpp"
#include "Model/components/SCRIPT/GenericScript.cpp"
#include "Model/components/SCRIPT/PlayerShipActions.cpp"
#include "Model/components/SCRIPT/EnemyShipActions.cpp"
#include "Model/components/SCRIPT/BulletMoveScript.cpp"
#include "Model/components/SCRIPT/PowerupScript.cpp"
#include "Model/components/SCRIPT/SpawnerScript.cpp"
#include "Model/components/SCRIPT/BaseCaptureScript.cpp"
#include "Model/components/SCRIPT/MatchTrackerScript.cpp"
#include "Model/components/SCRIPT/ScoreUIScript.cpp"
#include "Model/components/SCRIPT/TimerUIScript.cpp"
#include "Model/components/SCRIPT/MainMenuPromptScript.cpp"
#include "Model/components/SCRIPT/MapSelectPromptScript.cpp"
#include "Model/components/SCRIPT/ResultsPromptScript.cpp"
#include "Model/components/SCRIPT/QuitPromptScript.cpp"
#include "Model/components/SCRIPT/ArenaPromptScript.cpp"
#include "Model/components/SCRIPT/SettingPromptScript.cpp"

#include "Model/GameObject.cpp"
#include "Model/ObjectPool.cpp"

#include "Model/entities/Entity.cpp"
#include "Model/entities/Powerup.cpp"

#include "Model/entities/TeamMember.cpp"
#include "Model/entities/Ship.cpp"
#include "Model/entities/PlayerShip.cpp"
#include "Model/entities/EnemyShip.cpp"
#include "Model/entities/BalanceEnemy.cpp"
#include "Model/entities/AggroEnemy.cpp"
#include "Model/entities/DefenseEnemy.cpp"
#include "Model/entities/Bullet.cpp"
#include "Model/entities/Base.cpp"

#include "Model/systems/System.cpp"
#include "Model/systems/Spawner.cpp"
#include "Model/systems/MatchTracker.cpp"

#include "Model/uiElements/Background.cpp"
#include "Model/uiElements/TextElement.cpp"
#include "Model/uiElements/ScoreUI.cpp"
#include "Model/uiElements/TimerUI.cpp"

#include "Model/scenes/Scene.cpp"
#include "Model/scenes/MainMenuScene.cpp"
#include "Model/scenes/QuitScene.cpp"
#include "Model/scenes/ArenaScene.cpp"
#include "Model/scenes/ResultsScene.cpp"
#include "Model/scenes/SettingsScene.cpp"

#include "Controller/Game.cpp"

/***********************************************/

int main(){
    Game::Instance()->run();
    return 0;
}