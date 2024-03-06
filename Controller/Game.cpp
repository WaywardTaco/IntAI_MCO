
#include "Game.hpp"

using namespace controllers;

Game::Game() : 
    window(Settings::Instance()->getWindowDim(), Settings::Instance()->getWindowName()),
    windowToClose(false){}

void Game::run(){
    sf::Clock clock;
    sf::Time timeSinceUpdate = sf::Time::Zero;

    this->window.setFramerateLimit(Settings::Instance()->getFrameLimit());

    SceneManager::Instance()->loadScene(SceneTag::MAIN_MENU);

    while(this->window.isOpen()){
        sf::Time timePerFrame = Settings::Instance()->getFrameTime();
        timeSinceUpdate += clock.restart();

        while(timeSinceUpdate > timePerFrame){
            timeSinceUpdate -= timePerFrame;

            this->processEvents();
            this->update();
        }

        SceneManager::Instance()->checkLoadScene();
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
    if(this->windowToClose){
        window.close();
    }

    ObjectManager::Instance()->update(Settings::Instance()->getFrameTime());
}

void Game::render(){
    this->window.clear();

    ObjectManager::Instance()->draw(&this->window);

    this->window.display();
}

