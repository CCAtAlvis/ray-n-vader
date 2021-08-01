#ifndef enemy
#define enemy

#include <vector>
#include "raylib.h"

class Enemy {
 public:
  float radius;
  Vector2 center;

 public:
  static std::vector<Enemy> enemies;

  Enemy();
  void Draw();
  void Update();
};

#endif