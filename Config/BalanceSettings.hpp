
#pragma once

const float
    // Bullets should be notably faster than the ship
    SHIP_SPEED = 400.f,
    BULLET_SPEED = 1000.f,

    BULLET_MAX_SECONDS = 0.5f,
    SPAWN_SECONDS = 1.f,
    SHIP_MAX_HEALTH = 10.f,

    MINE_DAMAGE = 5.f,
    SHIELD_TIMELIMIT = 10.f,

    BASE_MAX_HEALTH = 15.f,
    BULLET_DAMAGE = 3.f,
    MATCH_SECONDS = 120.f,
    POWERUP_SPAWN_DELAY = 15.f,

    BASE_CAPTURE_TIME = 2.f,
    BASE_CAPTURE_DEGRADE_RATE = 0.5f,
    BASE_CAPTURE_RATE = 1.f,

    SHIP_SPAWN_RADIUS = 200.f
    ;

const int
    MAX_PLAYER_BULLETS = 3,
    MAX_MINES = 5,
    MAX_CHAOS = 2,
    MAX_SHIELDS = 3;