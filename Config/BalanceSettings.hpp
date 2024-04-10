
#pragma once

const float
    // Bullets should be notably faster than the ship
    SHIP_SPEED = 300.f,
    BULLET_SPEED = 700.f,
    POWERUP_DRIFT_SPEED = 10.f,

    BULLET_MAX_SECONDS = 0.5f,
    SPAWN_SECONDS = 1.f,
    SHIP_MAX_HEALTH = 10.f,

    MINE_DAMAGE = SHIP_MAX_HEALTH,
    SHIELD_TIMELIMIT = 10.f,

    BASE_MAX_HEALTH = 15.f,
    BULLET_DAMAGE = 3.f,
    MATCH_SECONDS = 120.f,
    POWERUP_SPAWN_DELAY = 15.f,

    BASE_CAPTURE_TIME = 2.f,
    BASE_CAPTURE_DEGRADE_RATE = 0.5f,
    BASE_CAPTURE_RATE = 1.f,

    SHIP_SPAWN_RADIUS = 100.f
    ;

const int
    MAX_PLAYER_BULLETS = 3,
    MAX_ENEMY_BULLETS = 5,

    MAP_PLAIN_MAX_MINES = 10,
    MAP_PLAIN_MAX_CHAOS = 3,
    MAP_PLAIN_MAX_SHIELDS = 4,
    MAP_PLAIN_MAX_BASES = 3,

    MAP_MINE_MAX_MINES = 14,
    MAP_MINE_MAX_CHAOS = 3,
    MAP_MINE_MAX_SHIELDS = 3,
    MAP_MINE_MAX_BASES = 4,

    MAP_CHAOS_MAX_MINES = 7,
    MAP_CHAOS_MAX_CHAOS = 9,
    MAP_CHAOS_MAX_SHIELDS = 4,
    MAP_CHAOS_MAX_BASES = 4,

    MAP_SHIELD_MAX_MINES = 5,
    MAP_SHIELD_MAX_CHAOS = 3,
    MAP_SHIELD_MAX_SHIELDS = 7,
    MAP_SHIELD_MAX_BASES = 4
    ;

const int
    SCORE_PER_KILL = 100,
    SCORE_PER_DEATH = -200,
    SCORE_PER_BASE_LEFT = 200,
    SCORE_PER_BASE_DESTROYED = 200,
    SCORE_PER_SECOND_LEFT = 10;