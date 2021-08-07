#include <iostream>
#include <vector>

#include "raylib.h"
#include "raymath.h"

#include "../headers/game.h"
#include "../headers/bullet.h"
#include "../headers/player.h"

Bullet::Bullet(Vector2 v, float rotation) {
  direction.x = cosf((rotation - 90) * DEG2RAD);
  direction.y = sinf((rotation - 90) * DEG2RAD);
  center = v;
  bulletes.push_back(*this);
  isEnabled = true;
}

Bullet::~Bullet() {}

void Bullet::Draw() {
  if (!isEnabled) return;
  DrawCircle(center.x, center.y, RADIUS, BULLET_COLOR);
}

void Bullet::Update() {
  if (!isEnabled) return;

  center.x += direction.x * SPEED;
  center.y += direction.y * SPEED;

  // TODO: destroy bullet on colliding walls
  // if (center.x > Const::screenWidth || center.x < 0 || center.y < 0 ||
  //     center.y > Const::screenHeight) {
  //   this->~Bullet();
  // }
}

void Bullet::Disable() { isEnabled = false; }

std::vector<Bullet> Bullet::bulletes;
