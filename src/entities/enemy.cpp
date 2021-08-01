#include <iostream>
#include <vector>

#include "../headers/player.h"
#include "../headers/enemy.h"
#include "raylib.h"

Vector2 Player::position = {100, 100};
Vector2 Player::speed = {100, 100};

int screenWidth = 800;
int screenHeight = 450;
int screenMargin = 20;


std::vector<Enemy> Enemy::enemies;

int main() {
  InitWindow(screenWidth, screenHeight, "player test");

  screenWidth = GetScreenWidth();
  screenHeight = GetScreenHeight();

  SetTargetFPS(60);

  for (int i = 0; i < 30; ++i) {
    Enemy e;
  }

  while (!WindowShouldClose()) {
    ClearBackground(RAYWHITE);
    BeginDrawing();

    for (int i = 0; i < Enemy::enemies.size(); ++i) {
      Enemy::enemies[i].Draw();
      Enemy::enemies[i].Update();
    }

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
