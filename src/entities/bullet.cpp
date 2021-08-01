#include <iostream>
#include <vector>

#include "player.h"
#include "raylib.h"
#include "raymath.h"

Bullet::Bullet(Vector2 v, float rotation) {
  direction.x = cosf((rotation - 90) * DEG2RAD);
  direction.y = sinf((rotation - 90) * DEG2RAD);
  center = v;

  bulletes.push_back(*this);
}

Bullet::~Bullet() { std::cout << "bullet destroyed" << std::endl; }

void Bullet::Draw() { DrawCircle(center.x, center.y, RADIUS, BULLET_COLOR); }

void Bullet::Update() {
  center.x += direction.x * SPEED;
  center.y += direction.y * SPEED;
  // std::cout << direction.x << "\t" << direction.y << "\t" << center.x << "\t"
  // << center.y << std::endl;

  // TODO: destroy bullet on colliding walls
}

std::vector<Bullet> Bullet::bulletes;
