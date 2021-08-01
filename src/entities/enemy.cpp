#ifndef enemy
#define enemy

#include <vector>

#include "enemy.h"
#include "player.h"
#include "raylib.h"

Enemy::Enemy() {
  center = {
      GetRandomValue(-(screenMargin + radius), screenWidth + screenMargin),
      GetRandomValue(-(screenMargin + radius), screenHeight + screenMargin)};
  radius = 16;

  enemies.push_back(*this);
}

Enemy::Draw() { DrawCircle(center.x, center.y, radius, BLUE); }

Enemy::Update() {
  float xfactor = abs(center.x - Player::position.x);
  float yfactor = abs(center.y - Player::position.y);

  if (center.x < Player::position.x) center.x += xfactor / (xfactor + yfactor);
  if (center.x > Player::position.x) center.x -= xfactor / (xfactor + yfactor);
  if (center.y < Player::position.y) center.y += yfactor / (xfactor + yfactor);
  if (center.y > Player::position.y) center.y -= yfactor / (xfactor + yfactor);
}

std::vector<Enemy> Enemy::enemies;

#endif