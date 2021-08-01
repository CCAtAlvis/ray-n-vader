#pragma once

#include <math.h>

#include "raylib.h"

#include "player.h"

class Bullet {
 private:
  static constexpr float RADIUS = 4;
  static constexpr Color BULLET_COLOR = RED;
  static constexpr float SPEED = 10;

 public:
  Vector2 center;
  Vector2 direction;

  Bullet() {
    direction.x = sin(Player::rotation * DEG2RAD);
    direction.y = cos(Player::rotation * DEG2RAD);
  }

  void draw() { DrawCircle(center.x, center.y, RADIUS, BULLET_COLOR); }

  void update() {
    center.x += direction.x * SPEED;
    center.y += direction.y * SPEED;
  }
};
