#ifndef bullet
#define bullet

#include <vector>
#include "raylib.h"

class Bullet {
 private:
  static constexpr Color BULLET_COLOR = RED;
  static constexpr float SPEED = 7;

 public:
  static constexpr float RADIUS = 4;
  static std::vector<Bullet> bulletes;

  Vector2 center;
  Vector2 direction;

  Bullet(Vector2 v, float rotation);
  ~Bullet();
  void Draw();
  void Update();
};

#endif
