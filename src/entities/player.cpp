#include <math.h>

// #include <stdlib.h>
// #include <iostream>

#include "raylib.h"
#include "raymath.h"

#include "player.h"

// int screenWidth;
// int screenHeight;
int screenWidth = 800;
int screenHeight = 450;
int screenMargin = 20;

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
