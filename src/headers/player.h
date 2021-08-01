#pragma once

#include "raylib.h"

class Player
{
private:
    static const int SHIP_HEIGHT;
    static const int SHIP_WIDTH;
    static const int TURRET_SIZE;
    static const int TURRET_TRANSLATION;
    static const float PLAYER_SPEED;

public:
    static Vector2 position;
    static Vector2 speed;
    static float acceleration;
    static float rotation;
    static Color playerColor;
    static Color turretColor;

    static void Init();
    static void Draw();
    static void Update();
};
