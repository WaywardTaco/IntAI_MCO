
#pragma once

#include "../enums/SceneTag.hpp"
#include "../enums/TextureType.hpp"
#include "../enums/PowerupType.hpp"
#include "../enums/MapTypes.hpp"
#include "../enums/MusicType.hpp"
#include "../enums/SoundType.hpp"
#include "../../Controller/managers/AudioManager.hpp"
#include "../../Controller/managers/TextureManager.hpp"
#include "../../Controller/managers/ObjectManager.hpp"
#include "../../Controller/managers/ObjectPoolManager.hpp"
#include "../../Config/BalanceSettings.hpp"
#include "Scene.hpp"
#include "../uiElements/Background.hpp"
#include "../uiElements/TimerUI.hpp"
#include "../uiElements/ScoreUI.hpp"
#include "../entities/PlayerShip.hpp"
#include "../entities/BalanceEnemy.hpp"
#include "../entities/AggroEnemy.hpp"
#include "../entities/DefenseEnemy.hpp"
#include "../entities/Bullet.hpp"
#include "../entities/Powerup.hpp"
#include "../entities/Base.hpp"
#include "../systems/Spawner.hpp"
#include "../systems/MatchTracker.hpp"
#include "../ObjectPool.hpp"
#include "../../View/AnimateTexture.hpp"
#include "../components/SCRIPT/ArenaPromptScript.hpp"
#include "../components/INPUT/ArenaPromptInput.hpp"

namespace scenes {
    using namespace uiElements;
    using namespace managers;
    using namespace entities;
    using namespace view;
    class ArenaScene : public Scene {
        private:
            sf::Font uiFont;
            MapTypes currentMap;

        public:
            ArenaScene();

            void onLoadResources();
            void onLoadObjects();
            void passMap(MapTypes map);
            MapTypes getMap();
    };
}