#include "raylib.h"
#include <iostream>
class Enemy
{

public:
    float radius;
    Vector2 center;

    Enemy(float radius, int centerX, int centerY)
    {
        (*this).radius = radius;
        (*this).center = {centerX, centerY};
    }

    void draw()
    {
        DrawCircle(center.x, center.y, radius, RED);
    }

    void update()
    {
        // get player's position
        Vector2 player = {100, 100};
        center.x += 1;
        center.y += 1;
    }
};

int main()
{
    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();

    InitWindow(screenWidth, screenHeight, "test game");
    if (!IsWindowFullscreen())
        ToggleFullscreen();

    SetTargetFPS(60);

    Enemy e(10, 10, 15.0);
    while (!WindowShouldClose())
    {
        ClearBackground(RAYWHITE);
        BeginDrawing();

        e.draw();

        EndDrawing();

        e.update();
    }

    CloseWindow();
    return 0;
}
