
#pragma once

namespace managers{
    class SceneManager{
        public:
            void checkLoadScene();

        /* SINGLETON CODE */
        private:
            static SceneManager* SHARED_INSTANCE;
            SceneManager();
            SceneManager(const SceneManager&);
            SceneManager& operator = (const SceneManager&);
        public:
            static SceneManager* Instance();
    };
}