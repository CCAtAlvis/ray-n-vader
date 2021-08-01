#include "entities/enemy.h"
#include "entities/player.h"
#include "entities/bullet.h"
#include "raylib.h"

// Vector2 Player::position = {0, 0};
// Vector2 Player::speed = {100, 100};
// float Player::acceleration = 0;
// float Player::rotation = 0;
// Color Player::playerColor = RED;
// Color Player::turretColor = BLACK;

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
    // for (int i = 0; i < Enemy::enemies.size(); ++i) {
    //   Enemy::enemies[i].Draw();
    //   Enemy::enemies[i].Update();
    // }

    for (int i = 0; i < Bullet::bulletes.size(); ++i) {
      Bullet::bulletes[i].Draw();
      Bullet::bulletes[i].Update();
    }
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
