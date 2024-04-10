
#include "AudioManager.hpp"

using namespace managers;

void AudioManager::loadSound(SoundType soundType, std::string path){
    sf::SoundBuffer* buffer = new sf::SoundBuffer();
    if(!buffer->loadFromFile(path)){
        std::cout << "Error loading from file: " << path << std::endl;
        return;
    }

    this->mapSounds[soundType].push_back(buffer);
}

void AudioManager::loadMusic(MusicType musicType, std::string path){
    if(this->mapMusic[musicType] != NULL){
        this->mapMusic[musicType]->stop();
        delete this->mapMusic[musicType];
    }

    sf::Music* music = new sf::Music();
    if(!music->openFromFile(path)){
        std::cout << "Error loading from file: " << path << std::endl;
        return;
    }

    if(this->mapMusic[musicType] != NULL)
        delete this->mapMusic[musicType];

    this->mapMusic[musicType] = music;
}

void AudioManager::playSound(SoundType soundType, int index, int channel, float volume){
    if(this->mapSounds[soundType].size() <= 0){
        std::cout << "Empty" << std::endl;
        return;
    }
    
    if(index >= this->mapSounds[soundType].size())
        index = this->mapSounds[soundType].size() - 1;

    if(index < -1)
        index = 0;

    if(volume < 0.f)
        volume = 0;

    if(volume > 100.f)
        volume = 100.f;

    while(this->vecSoundChannels.size() <= channel)
        this->vecSoundChannels.push_back(NULL);

    if(this->vecSoundChannels[channel] == NULL)
        this->vecSoundChannels[channel] = new sf::Sound();

    this->vecSoundChannels[channel]->setBuffer(*this->mapSounds[soundType][index]);
    this->vecSoundChannels[channel]->setVolume(volume);

    this->vecSoundChannels[channel]->play();
}

void AudioManager::playMusic(MusicType musicType, float volume, float startTime){
    if(this->mapMusic[musicType] == NULL)
        return;

    if(this->playingMusic != NULL)
        this->playingMusic->stop();

    if(volume < 0.f)
        volume = 0.f;
    
    if(volume > 100.f)
        volume = 100.f;

    this->playingMusic = this->mapMusic[musicType];
    this->playingMusic->setVolume(volume);

    this->playingMusic->play();
    this->playingMusic->setPlayingOffset(sf::seconds(startTime));
}

void AudioManager::startMusic(){
    if(this->playingMusic != NULL)
        this->playingMusic->play();
}

void AudioManager::pauseMusic(){
    if(this->playingMusic != NULL)
        this->playingMusic->pause();
}

void AudioManager::stopMusic(){
    if(this->playingMusic != NULL)
        this->playingMusic->stop();
}

void AudioManager::clearAllAudio(){
    this->clearSounds();
    this->clearMusic();
}

void AudioManager::clearSounds(){
    for(sf::Sound* sound : this->vecSoundChannels){
        if(sound != NULL){
            sound->stop();
            sound->resetBuffer();
            delete sound;
        }
    }

    this->vecSoundChannels.clear();

    for(auto itr : this->mapSounds){
        for(sf::SoundBuffer* sound : itr.second){
            delete sound;
        }
        itr.second.clear();
    }

    this->mapSounds.clear();
}

void AudioManager::clearMusic(){
    this->stopMusic();
    this->playingMusic = NULL;

    for(auto itr : this->mapMusic)
        delete itr.second;

    this->mapMusic.clear();
}

/* SINGLETON RELATED CONTENT */
AudioManager* AudioManager::SHARED_INSTANCE = NULL;
AudioManager::AudioManager() : mapSounds(), mapMusic(), playingMusic(NULL){}
AudioManager::~AudioManager(){this->clearAllAudio();}
AudioManager::AudioManager(const AudioManager&){}
AudioManager* AudioManager::Instance(){
    if(SHARED_INSTANCE == NULL)
        SHARED_INSTANCE = new AudioManager;
    return SHARED_INSTANCE;
}
