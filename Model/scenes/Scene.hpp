
#pragma once

#include "../enums/SceneTag.hpp"
#include "../enums/TextureType.hpp"
#include "../../Controller/managers/ObjectManager.hpp"
#include "../../Controller/managers/TextureManager.hpp"

namespace scenes {
    using namespace managers;
    class Scene {
        protected:
            SceneTag tag;

        public:
            Scene(SceneTag tag);

            virtual void onLoadResources() = 0;
            virtual void onLoadObjects() = 0;
            virtual void onUnload();

            SceneTag getTag();
    };
}