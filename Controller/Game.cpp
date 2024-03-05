
#include "Game.hpp"

using namespace controllers;

Game::Game() : 
    window(Settings::Instance()->getWindowDim(), Settings::Instance()->getWindowName()),
    windowToClose(false)
{

}

void Game::run(){
    sf::Clock clock;
    sf::Time timeSinceUpdate = sf::Time::Zero;

    this->window.setFramerateLimit(60.f);

    while(this->window.isOpen()){
        timeSinceUpdate += clock.restart();

        while(timeSinceUpdate > Settings::Instance()->getFrameTime()){
            timeSinceUpdate -= Settings::Instance()->getFrameTime();

            this->processEvents();
            this->update();
        }

        TextureManager::Instance()->checkLoadScene();
        this->render();
    }
}

void Game::processEvents(){
    sf::Event event;

    while(this->window.pollEvent(event)){
        switch(event.type){
            case sf::Event::Closed:
                this->windowToClose = true;
                break;
            default:
                ObjectManager::Instance()->processEvents(event);
                break;
        }
    }

}

void Game::update(){
    if(this->windowToClose)
        window.close();

    ObjectManager::Instance()->update(Settings::Instance()->getFrameTime());
}

void Game::render(){
    this->window.clear();

    ObjectManager::Instance()->draw(&this->window);

    this->window.display();
}

