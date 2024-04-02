
#pragma once
#include <string>

const std::string
    GAME_NAME = "Space Conquest";

const unsigned int
    WINDOW_WIDTH = 1600,
    WINDOW_HEIGHT = 880;

const float
    FRAME_LIMIT = 60.f,
    FRAME_TIME = 1.f / 60.f;

const int
    SCORE_FONT_SIZE = 50,
    TIMER_FONT_SIZE = 60,
    PROMPT_FONT_SIZE = 100;

const sf::Vector2f 
    PLAYER_SCORE_POSITION = {10.f, 0.f},
    ENEMY_SCORE_POSITION = {10.f, 50.f},
    TIMER_UI_POSITION = {WINDOW_WIDTH - 175.f, 0.f},
    PROMPT_POSITION = {WINDOW_WIDTH / 2.f, WINDOW_HEIGHT - (WINDOW_HEIGHT / 4.f)};