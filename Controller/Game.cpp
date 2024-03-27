
#include "Game.hpp"

using namespace controllers;

Game::Game() : 
    window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), GAME_NAME),
    windowToClose(false)
{
    SceneManager::Instance()->loadScene(SceneTag::ARENA);
}

void Game::run(){
    sf::Clock clock;
    sf::Time timeSinceUpdate = sf::Time::Zero;

    this->window.setFramerateLimit(FRAME_LIMIT);

    sf::Time timePerFrame = sf::seconds(FRAME_TIME);
    while(this->window.isOpen()){
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

    ColliderManager::Instance()->processCollisions();
}

void Game::update(){
    if(this->windowToClose)
        window.close();

    ObjectManager::Instance()->update(sf::seconds(FRAME_TIME));
}

void Game::render(){
    this->window.clear();
    ObjectManager::Instance()->draw(&this->window);
    this->window.display();
}

/* SINGLETON CODE */
Game* Game::SHARED_INSTANCE = NULL;
Game::Game(const Game&){}
Game* Game::Instance(){
    if(SHARED_INSTANCE == NULL)
        SHARED_INSTANCE = new Game();

    return SHARED_INSTANCE;
}
