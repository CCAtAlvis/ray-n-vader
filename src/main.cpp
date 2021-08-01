#include "entities/enemy.h"
#include "entities/player.h"
#include "raylib.h"

#include "headers/collision_handler.h"

int main() {
  InitWindow(screenWidth, screenHeight, "player test");
  // if (!IsWindowFullscreen()) ToggleFullscreen();
  // screenWidth = GetScreenWidth();
  // screenHeight = GetScreenHeight();

  SetTargetFPS(60);

  Player::Init();
  for (int i = 0; i < 30; ++i) {
    Enemy e;
  }

  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(RAYWHITE);
    Player::Update();
    Player::Draw();
    for (int i = 0; i < Enemy::enemies.size(); ++i) {
      Enemy::enemies[i].Draw();
      Enemy::enemies[i].Update();
    }
    EndDrawing();
    CheckCollision();
  }

  CloseWindow();
  return 0;
}
