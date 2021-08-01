#include <math.h>

// #include <stdlib.h>
// #include <iostream>

#include "raylib.h"
#include "raymath.h"

// int screenWidth;
// int screenHeight;
int screenWidth = 800;
int screenHeight = 450;
int screenMargin = 20;

class Player
{
public:
    static const int SHIP_HEIGHT = 20;
    static const int SHIP_WIDTH = 20;
    static const int TURRET_SIZE = 20;
    static const int TURRET_TRANSLATION = 9;
    static constexpr float PLAYER_SPEED = 2.0;

    static Vector2 position;
    static Vector2 speed;
    static float acceleration;
    static float rotation;
    static Color playerColor;
    static Color turretColor;

    static void Init()
    {
        position = (Vector2){screenWidth / 2, screenHeight / 2 - SHIP_HEIGHT / 2};
    }

    static void Draw()
    {
        // rotate
        Vector2 v1 = {position.x + sinf(rotation * DEG2RAD) * (TURRET_SIZE), position.y - cosf(rotation * DEG2RAD) * (SHIP_HEIGHT)};
        Vector2 v2 = {position.x - cosf(rotation * DEG2RAD) * (TURRET_SIZE / 2), position.y - sinf(rotation * DEG2RAD) * (TURRET_SIZE / 2)};
        Vector2 v3 = {position.x + cosf(rotation * DEG2RAD) * (TURRET_SIZE / 2), position.y + sinf(rotation * DEG2RAD) * (TURRET_SIZE / 2)};

        // translate
        v1.x += sinf(rotation * DEG2RAD) * TURRET_TRANSLATION;
        v2.x += sinf(rotation * DEG2RAD) * TURRET_TRANSLATION;
        v3.x += sinf(rotation * DEG2RAD) * TURRET_TRANSLATION;
        v1.y -= cosf(rotation * DEG2RAD) * TURRET_TRANSLATION;
        v2.y -= cosf(rotation * DEG2RAD) * TURRET_TRANSLATION;
        v3.y -= cosf(rotation * DEG2RAD) * TURRET_TRANSLATION;
        DrawTriangle(v1, v2, v3, playerColor);

        DrawPoly(position, 4, SHIP_HEIGHT, rotation, playerColor);
    }

    static void Update()
    {
        if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A))
            rotation -= 5;
        if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D))
            rotation += 5;

        if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W))
        {
            if (acceleration < 1)
                acceleration += 0.04f;
        }

        if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_D))
        {
            if (acceleration > -1)
                acceleration -= 0.04f;
        }

        speed.x = sin(rotation * DEG2RAD) * PLAYER_SPEED;
        speed.y = cos(rotation * DEG2RAD) * PLAYER_SPEED;

        if (position.x > screenWidth - SHIP_WIDTH - screenMargin)
            position.x = screenWidth - SHIP_WIDTH - screenMargin;
        else if (position.x < SHIP_WIDTH + screenMargin)
            position.x = SHIP_WIDTH + screenMargin;

        if (position.y > screenHeight - SHIP_HEIGHT - screenMargin)
            position.y = screenHeight - SHIP_HEIGHT - screenMargin;
        else if (position.y < SHIP_HEIGHT + screenMargin)
            position.y = SHIP_HEIGHT + screenMargin;

        position.x += (speed.x * acceleration);
        position.y -= (speed.y * acceleration);

        acceleration = Lerp(acceleration, 0, 0.03f);

        if (IsKeyPressed(KEY_SPACE)) {
            
        }
    }
};

Vector2 Player::position = (Vector2){0, 0};
Vector2 Player::speed = (Vector2){100, 100};
float Player::acceleration = 0;
float Player::rotation = 0;
Color Player::playerColor = RED;
Color Player::turretColor = BLACK;

int main()
{
    InitWindow(screenWidth, screenHeight, "player test");
    // if (!IsWindowFullscreen()) ToggleFullscreen();

    screenWidth = GetScreenWidth();
    screenHeight = GetScreenHeight();

    SetTargetFPS(60);

    Player::Init();

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);
        Player::Update();
        Player::Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
