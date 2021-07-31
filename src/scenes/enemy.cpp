#include "raylib.h"

int main()
{
    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();

    InitWindow(screenWidth, screenHeight, "test game");
    if (!IsWindowFullscreen())
        ToggleFullscreen();

    SetTargetFPS(60);

    bool key = false;
    while (!WindowShouldClose())
    {
        // key = IsKeyDown(KEY_CAPS_LOCK);

        BeginDrawing();

        // ClearBackground(RAYWHITE);

        DrawCircle(10, 10, 15.0, RED);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
