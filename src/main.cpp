#include <iostream>

#include "raylib.h"

#include "headers/game.h"
#include "headers/enemy.h"
#include "headers/player.h"
#include "headers/bullet.h"

#include "headers/collision_handler.h"
#include "headers/gui.h"

// int Const::screenWidth = 800;
// int Const::screenHeight = 450;
int Const::screenWidth = 0;
int Const::screenHeight = 0;

int Const::screenMargin = 20;
int Const::score = 0;

bool Const::isGameOver = false;
bool Const::isGamePaused = false;

int main() {
  InitWindow(Const::screenWidth, Const::screenHeight, "Ray N Vader");
  if (!IsWindowFullscreen()) ToggleFullscreen();
  Const::screenWidth = GetScreenWidth();
  Const::screenHeight = GetScreenHeight();
  Const::screenMargin = 20;

  SetExitKey(0);
  SetTargetFPS(60);

  DrawRaylibLogo();
  bool shouldStart = ShowStartMenu();
  if (!shouldStart) {
    CloseWindow();
    return 0;
  }

  Player::Init();
  for (int i = 0; i < 30; ++i) {
    Enemy e;
  }

  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(RAYWHITE);

    ScoreGui();
    GameOverGui();

    if (Const::isGameOver && IsKeyPressed(KEY_ESCAPE)) break;

    if (Const::isGamePaused || Const::isGameOver) {
      EndDrawing();
      continue;
    }

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
    CheckBulletCollision();
    CheckPlayerCollision();
  }

  CloseWindow();
  return 0;
}
