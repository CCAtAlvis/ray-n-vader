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
        key = IsKeyDown(KEY_CAPS_LOCK);

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        DrawText("caps lock " + (int)key, 190, 250, 20, LIGHTGRAY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
