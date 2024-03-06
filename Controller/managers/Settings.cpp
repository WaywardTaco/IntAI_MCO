
#include "Settings.hpp"

#include <iostream>
using namespace managers;

Settings::Settings() 
// : 
//     windowDim(800, 440),
//     windowName("Aviso, Baniqued, & Taylan"),
//     frameTime(sf::seconds(1.f / 60.f)),
//     frameLimit(60.f)
    {  
        this->windowDim = sf::VideoMode(800, 440);
        this->windowName = ("Aviso, Baniqued, & Taylan");
        this->frameTime = (sf::seconds(1.f / 60.f));
        this->frameLimit = 60.f;
    }

void Settings::setWindowDim(unsigned int height, unsigned int width){
    this->windowDim = sf::VideoMode(width, height);
}

sf::VideoMode Settings::getWindowDim(){
    return this->windowDim;
}

void Settings::setWindowName(std::string name){
    this->windowName = name;
}

std::string Settings::getWindowName(){
    return this->windowName;
}

void Settings::setFrameTime(sf::Time time){
    this->frameTime = time;
}

sf::Time Settings::getFrameTime(){
    return this->frameTime;
}

void Settings::setFrameLimit(float limit){
    this->frameLimit = limit;
}

float Settings::getFrameLimit(){
    return this->frameLimit;
}

/* SINGLETON CODE */
Settings* Settings::SHARED_INSTANCE = NULL;
Settings::Settings(const Settings&){}
Settings* Settings::Instance(){        
    if(SHARED_INSTANCE == NULL)
        SHARED_INSTANCE = new Settings();

    return SHARED_INSTANCE;
}
