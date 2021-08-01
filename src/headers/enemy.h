#pragma once

#include "raylib.h"

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
    if (center.x < Player::position.x) center.x += 1;
    if (center.x > Player::position.x) center.x -= 1;
    if (center.y < Player::position.y) center.y += 1;
    if (center.y > Player::position.y) center.y -= 1;
  }
};