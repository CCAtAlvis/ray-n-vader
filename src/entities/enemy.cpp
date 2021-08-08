#include <vector>
#include <iostream>

#include "raylib.h"
#include "raymath.h"

#include "../headers/game.h"
#include "../headers/enemy.h"
#include "../headers/player.h"

Enemy::Enemy() {}

Enemy::Enemy(int i) {
  radius = 16;
  unitStrength = 20;
  life = 20 * GetRandomValue(1, 3);

  int quadrant = GetRandomValue(1, 4);
  if (quadrant == 1) {
    center = {0, GetRandomValue(0, Const::screenHeight)};
  } else if (quadrant == 2) {
    center = {Const::screenWidth, GetRandomValue(0, Const::screenHeight)};
  } else if (quadrant == 3) {
    center = {GetRandomValue(0, Const::screenWidth), 0};
  } else if (quadrant == 4) {
    center = {GetRandomValue(0, Const::screenWidth), Const::screenHeight};
  }

  enemies[i] = *this;
}

void Enemy::Draw() {
  radius = 16;
  int incrementalRadius = 8;
  for (int i = (life / unitStrength) - 1; i >= 0; i--) {
    DrawCircle(center.x, center.y, radius + (incrementalRadius * i), Const::enemyStrengthColors[i]);
  }
  radius += (incrementalRadius * (life / unitStrength));
}

void Enemy::Update() {
  float xfactor = abs(center.x - Player::position.x);
  float yfactor = abs(center.y - Player::position.y);

  if (center.x < Player::position.x) center.x += xfactor / (xfactor + yfactor);
  if (center.x > Player::position.x) center.x -= xfactor / (xfactor + yfactor);
  if (center.y < Player::position.y) center.y += yfactor / (xfactor + yfactor);
  if (center.y > Player::position.y) center.y -= yfactor / (xfactor + yfactor);
}

void Enemy::TakeDamage(int damage) {
  life -= damage;
  if (life == 0)
    Reset();
}

void Enemy::Reset() {
  int quadrant = GetRandomValue(1, 4);
  if (quadrant == 1) {
    center = {0, GetRandomValue(0, Const::screenHeight)};
  } else if (quadrant == 2) {
    center = {Const::screenWidth, GetRandomValue(0, Const::screenHeight)};
  } else if (quadrant == 3) {
    center = {GetRandomValue(0, Const::screenWidth), 0};
  } else if (quadrant == 4) {
    center = {GetRandomValue(0, Const::screenWidth), Const::screenHeight};
  }
}

Enemy Enemy::enemies[];
std::vector<Color> Const::enemyStrengthColors;
