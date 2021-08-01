#include <iostream>
#include <vector>

#include "../headers/game.h"
#include "bullet.h"
#include "player.h"
#include "raylib.h"
#include "raymath.h"

Bullet::Bullet(Vector2 v, float rotation) {
  direction.x = cosf((rotation - 90) * DEG2RAD);
  direction.y = sinf((rotation - 90) * DEG2RAD);
  center = v;
  bulletes.push_back(*this);
}

// Bullet::~Bullet() { std::cout << "bullet destroyed" << std::endl; }

void Bullet::Draw() { DrawCircle(center.x, center.y, RADIUS, BULLET_COLOR); }

void Bullet::Update() {
  center.x += direction.x * SPEED;
  center.y += direction.y * SPEED;

  // TODO: destroy bullet on colliding walls
  // if (center.x > Const::screenWidth || center.x < 0 || center.y < 0 ||
  //     center.y > Const::screenHeight) {
  //   this->~Bullet();
  // }
}

std::vector<Bullet> Bullet::bulletes;
