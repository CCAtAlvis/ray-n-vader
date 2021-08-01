#ifndef bullet
#define bullet

#include <math.h>

#include "player.h"
#include "raylib.h"

class Bullet {
 private:
  static constexpr float RADIUS = 4;
  static constexpr Color BULLET_COLOR = RED;
  static constexpr float SPEED = 10;

 public:
  Vector2 center;
  Vector2 direction;

  Bullet() { }

  void draw() { DrawCircle(center.x, center.y, RADIUS, BULLET_COLOR); }

  void update() {
    center.x += direction.x * SPEED;
    center.y += direction.y * SPEED;

    // TODO: destroy bullet on colliding walls
  }
};

#endif
