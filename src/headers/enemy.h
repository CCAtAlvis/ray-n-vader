#pragma once

#include "raylib.h"
#include "game.h"
#include <vector>

#include "../headers/player.h"



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