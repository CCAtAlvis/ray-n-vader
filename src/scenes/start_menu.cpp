#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#define RAYGUI_SUPPORT_ICONS
#include "raygui.h"

#undef RAYGUI_IMPLEMENTATION

#include "../headers/game.h"

bool ShowStartMenu() {
  const int width = 200;
  const int height = 50;
  const int x = Const::screenWidth/2 - width/2;
  const int y = Const::screenHeight/2 - height/2;

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    if (GuiButton((Rectangle){x, y, width, height}, "") || (IsGamepadAvailable(0) && IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_FACE_DOWN))) {
      return true;
    }
    DrawText("Start", x+ width/4, y+ height/4-5, 40, BLACK);
    EndDrawing();
  }

  return false;
}
