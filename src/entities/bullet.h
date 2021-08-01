#pragma once

#include <iostream>
#include <vector>

#include "player.h"
#include "raylib.h"
#include "raymath.h"

class Bullet {
 private:
  static constexpr float RADIUS = 4;
  static constexpr Color BULLET_COLOR = RED;
  static constexpr float SPEED = 2;

 public:
  static std::vector<Bullet> bulletes;

  Vector2 center;
  Vector2 direction;

  Bullet(Vector2 v, float rotation) {
    direction.x = cosf((rotation-90) * DEG2RAD);
    direction.y = sinf((rotation-90) * DEG2RAD);
    center = v;

    bulletes.push_back(*this);
  }

  ~Bullet() {
    std::cout << "bullet destroyed" << std::endl;
  }

  void Draw() { DrawCircle(center.x, center.y, RADIUS, BULLET_COLOR); }

  void Update() {
    center.x += direction.x * SPEED;
    center.y += direction.y * SPEED;
    // std::cout << direction.x << "\t" << direction.y << "\t" << center.x << "\t" << center.y << std::endl;

    // TODO: destroy bullet on colliding walls
  }
};

std::vector<Bullet> Bullet::bulletes;