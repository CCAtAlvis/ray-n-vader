#include <iostream>

#include "headers/game.h"
#include "entities/enemy.h"
#include "entities/player.h"
#include "entities/bullet.h"
#include "raylib.h"

#include "headers/collision_handler.h"

// int Const::screenWidth = 800;
// int Const::screenHeight = 450;
int Const::screenWidth = 0;
int Const::screenHeight = 0;

int Const::screenMargin = 20;
int Const::score = 0;

bool Const::isGameOver = false;
bool Const::isGamePaused = false;

void DrawRaylibLogo();
bool ShowStartMenu();
void ScoreGui();
void GameOverGui();

int main(int argc, char **argv) {
  InitWindow(Const::screenWidth, Const::screenHeight, "Ray N Vader");
  if (!IsWindowFullscreen()) ToggleFullscreen();
  Const::screenWidth = GetScreenWidth();
  Const::screenHeight = GetScreenHeight();
  Const::screenMargin = 20;

  SetExitKey(0);
  SetTargetFPS(60);

#ifndef test
  DrawRaylibLogo();
  bool shouldStart = ShowStartMenu();
  if (!shouldStart) {
    CloseWindow();
    return 0;
  }
#endif

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
