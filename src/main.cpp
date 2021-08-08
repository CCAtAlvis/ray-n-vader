#include <iostream>

#include "raylib.h"

#include "headers/game.h"
#include "headers/enemy.h"
#include "headers/player.h"
#include "headers/bullet.h"

#include "headers/collision_handler.h"
#include "headers/gui.h"

// NOTE: Gamepad name ID depends on drivers and OS
#define XBOX360_LEGACY_NAME_ID  "Xbox Controller"
#if defined(PLATFORM_RPI)
    #define XBOX360_NAME_ID     "Microsoft X-Box 360 pad"
    #define PS3_NAME_ID         "PLAYSTATION(R)3 Controller"
#else
    #define XBOX360_NAME_ID     "Xbox 360 Controller"
    #define PS3_NAME_ID         "PLAYSTATION(R)3 Controller"
#endif

int Const::screenWidth = 800;
int Const::screenHeight = 450;

#ifdef build
int Const::screenWidth = 0;
int Const::screenHeight = 0;
#endif

int Const::screenMargin = 20;
int Const::score = 0;

bool Const::isGameOver = false;
bool Const::isGamePaused = false;

int main(int argc, char **argv) {
  InitWindow(Const::screenWidth, Const::screenHeight, "Ray N Vader");
  Const::enemyStrengthColors.push_back(DARKBLUE);
  Const::enemyStrengthColors.push_back(BLUE);
  Const::enemyStrengthColors.push_back(SKYBLUE);

  SetExitKey(0);
  SetTargetFPS(60);

#ifdef build
  if (!IsWindowFullscreen()) ToggleFullscreen();
  Const::screenWidth = GetScreenWidth();
  Const::screenHeight = GetScreenHeight();
  Const::screenMargin = 20;

  DrawRaylibLogo();
  bool shouldStart = ShowStartMenu();
  if (!shouldStart) {
    CloseWindow();
    return 0;
  }
#endif

  Player::Init();
  for (int i = 0; i < 30; ++i) {
    Enemy e(i);
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

    Player::ControllerUpdate();
    Player::KeyboardUpdate();
    Player::Update();
    Player::Draw();

    for (int i = 0; i < std::size(Enemy::enemies); ++i) {
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
