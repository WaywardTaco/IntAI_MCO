
#pragma once

enum class EnemyState : int {
    NONE = -1,
    BASE_CHASE = 0,
    BASE_PROTECTION = 1,
    PICKUP_MODE = 2,
    PLAYER_CHASE = 3
};