
#pragma once

namespace managers{
    class SceneManager{


        /* SINGLETON CODE */
        private:
            static SceneManager* SHARED_INSTANCE;
            SceneManager();
            SceneManager(const SceneManager&);
            SceneManager& operator = (const SceneManager&);
        public:
            SceneManager* Instance();
    };
}