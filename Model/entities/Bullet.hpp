
#pragma once

#include "TeamMember.hpp"
#include "../enums/ObjectType.hpp"
#include "../enums/FacingDir.hpp"
#include "../components/COLLIDER/ColliderBase.hpp"
#include "../components/RENDERER/GenericRenderer.hpp"
#include "../components/SCRIPT/BulletMoveScript.hpp"
#include "../enums/SoundType.hpp"
#include "../../Controller/managers/AudioManager.hpp"

namespace entities {
    using namespace components;
    using namespace managers;
    class Bullet : public TeamMember {
        public:
            Bullet(std::string name, GameObject* owner);
            void initialize();
            void onActivate();
            void onRelease();
            GameObject* copy();

            void kill();
    };
}