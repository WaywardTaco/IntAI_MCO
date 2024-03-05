
#pragma once

namespace managers{
    class TextureManager{
        public:
            void checkLoadScene();

        /* SINGLETON CODE */
        private:
            static TextureManager* SHARED_INSTANCE;
            TextureManager();
            TextureManager(const TextureManager&);
            TextureManager& operator = (const TextureManager&);
        public:
            static TextureManager* Instance();
    };
}