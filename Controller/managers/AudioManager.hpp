
#pragma once

#include <SFML/Audio.hpp>
#include <unordered_map>

#include "../../Model/enums/SoundType.hpp"
#include "../../Model/enums/MusicType.hpp"

namespace managers {
    class AudioManager {
        private:
            std::unordered_map<SoundType, sf::SoundBuffer*> mapSounds;
            std::unordered_map<MusicType, sf::Music*> mapMusic;
            sf::Music* playingMusic;
            std::vector<sf::Sound*> vecSoundChannels;

        public:
            void loadSound(SoundType soundType, std::string path);
            void loadMusic(MusicType musicType, std::string path);

            void playSound(SoundType soundType, int index, int channel, float volume);
            void playMusic(MusicType musicType, float volume);

            void startMusic();
            void pauseMusic();
            void stopMusic();

            void clearAllAudio();
            void clearSounds();
            void clearMusic();

        /* SINGLETON RELATED CONTENT */
        private:
            static AudioManager* SHARED_INSTANCE;
            AudioManager();
            AudioManager(const AudioManager&);
            AudioManager& operator = (const AudioManager&);
        public:
            static AudioManager* Instance();
    };
}