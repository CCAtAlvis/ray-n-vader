#include <vector>

#include "../headers/game.h"
#include "enemy.h"
#include "player.h"
#include "raylib.h"
#include "raymath.h"

Enemy::Enemy() {
  center = {
      GetRandomValue(-(Const::screenMargin + radius), Const::screenWidth + Const::screenMargin),
      GetRandomValue(-(Const::screenMargin + radius), Const::screenHeight + Const::screenMargin)};
  radius = 16;

  enemies.push_back(*this);
}

void Enemy::Draw() { DrawCircle(center.x, center.y, radius, BLUE); }

void Enemy::Update() {
  float xfactor = abs(center.x - Player::position.x);
  float yfactor = abs(center.y - Player::position.y);

  if (center.x < Player::position.x) center.x += xfactor / (xfactor + yfactor);
  if (center.x > Player::position.x) center.x -= xfactor / (xfactor + yfactor);
  if (center.y < Player::position.y) center.y += yfactor / (xfactor + yfactor);
  if (center.y > Player::position.y) center.y -= yfactor / (xfactor + yfactor);
}

std::vector<Enemy> Enemy::enemies;
