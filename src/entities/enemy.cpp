#include <vector>

#include "../headers/player.h"
#include "raylib.h"

Vector2 Player::position = {100, 100};
Vector2 Player::speed = {100, 100};

int screenWidth = 800;
int screenHeight = 450;
int screenMargin = 20;

class Enemy {
 public:
  float radius;
  Vector2 center;

 public:
  static std::vector<Enemy> enemies;
  Enemy() {
    center = {
        GetRandomValue(-(screenMargin + radius), screenWidth + screenMargin),
        GetRandomValue(-(screenMargin + radius), screenHeight + screenMargin)};
    radius = 16;

    enemies.push_back(*this);
  }

  void Draw() { DrawCircle(center.x, center.y, radius, BLUE); }

  void Update() {
    float xfactor = abs(center.x - Player::position.x);
    float yfactor = abs(center.y - Player::position.y);

    if (center.x < Player::position.x)
      center.x += xfactor / (xfactor + yfactor);
    if (center.x > Player::position.x)
      center.x -= xfactor / (xfactor + yfactor);
    if (center.y < Player::position.y)
      center.y += yfactor / (xfactor + yfactor);
    if (center.y > Player::position.y)
      center.y -= yfactor / (xfactor + yfactor);
  }
};

std::vector<Enemy> Enemy::enemies;
int main() {
  InitWindow(screenWidth, screenHeight, "enemy test");

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
