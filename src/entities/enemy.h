#ifndef enemy
#define enemy

#include <vector>
#include "raylib.h"

class Enemy {
 public:
  float radius;
  Vector2 center;
  int life;
  int unitStrength;

 public:
  static std::vector<Enemy> enemies;

  Enemy();
  void TakeDamage(int damage);
  void Reset();
  void Draw();
  void Update();
};

#endif