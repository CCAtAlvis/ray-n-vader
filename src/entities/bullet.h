#ifndef bullet
#define bullet

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

  Bullet(Vector2 v, float rotation);
  ~Bullet();
  void Draw();
  void Update();
};

#endif
