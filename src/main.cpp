#include "headers/game.h"
#include "entities/enemy.h"
#include "entities/player.h"
#include "entities/bullet.h"
#include "raylib.h"

// #include "headers/collision_handler.h"

int Const::screenWidth = 0;
int Const::screenHeight = 0;
int Const::screenMargin = 20;

int main() {
  InitWindow(Const::screenWidth, Const::screenHeight, "player test");
  if (!IsWindowFullscreen()) ToggleFullscreen();
  // screenWidth = GetScreenWidth();
  // screenHeight = GetScreenHeight();
  Const::screenWidth = GetScreenWidth();
  Const::screenHeight = GetScreenWidth();
  Const::screenMargin = 20;

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

    for (int i = 0; i < Bullet::bulletes.size(); ++i) {
      Bullet::bulletes[i].Draw();
      Bullet::bulletes[i].Update();
    }
    EndDrawing();
    // CheckCollision();
  }

  CloseWindow();
  return 0;
}
