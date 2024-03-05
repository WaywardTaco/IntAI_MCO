
#pragma once

#include "../enums/SceneTag.hpp"

namespace scenes {
    class Scene {
        private:
            SceneTag tag;

        public:
            Scene(SceneTag tag);

            virtual void onLoadResources() = 0;
            virtual void onLoadObjects() = 0;
            virtual void onUnloadResources() = 0;

            SceneTag getTag();
    };
}