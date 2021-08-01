
#include <vector>
#include <iostream>
#include "raylib.h"
class Enemy
{

public:
    float radius;
    Vector2 center;

    Enemy(float r, int x, int y)
    {
        radius = r;
        center = {x, y};
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
    int screenWidth = 600;
    int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "test game");
    if (!IsWindowFullscreen())
        ToggleFullscreen();

    SetTargetFPS(60);

    std::vector<Enemy> enemies;

    for (int i = 0; i < 30; ++i)
    {
        int x = GetRandomValue(1, screenWidth);
        int y = GetRandomValue(1, screenHeight);
        int radius = GetRandomValue(6, 10);
        Enemy e(radius, x, y);
        enemies.push_back(e);
    }

    while (!WindowShouldClose())
    {
        ClearBackground(RAYWHITE);
        BeginDrawing();

        for (int i = 0; i < 30; ++i)
        {
            enemies[i].draw();
            enemies[i].update();
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
