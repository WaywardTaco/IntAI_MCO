
#pragma once

#include "../enums/SceneTag.hpp"
#include "../enums/TextureType.hpp"
#include "../enums/PowerupType.hpp"
#include "../../Controller/managers/TextureManager.hpp"
#include "../../Controller/managers/ObjectManager.hpp"
#include "../../Controller/managers/ObjectPoolManager.hpp"
#include "Scene.hpp"
#include "../uiElements/Background.hpp"
#include "../entities/PlayerShip.hpp"
#include "../entities/Bullet.hpp"
#include "../entities/Powerup.hpp"
#include "../ObjectPool.hpp"
#include "../../View/AnimateTexture.hpp"

namespace scenes {
    using namespace uiElements;
    using namespace managers;
    using namespace entities;
    using namespace view;
    class ArenaScene : public Scene {
        public:
            ArenaScene();

            void onLoadResources();
            void onLoadObjects();
    };
}