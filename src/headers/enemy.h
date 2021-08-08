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
  static Enemy enemies[30];

  Enemy();
  Enemy(int i);

  void TakeDamage(int damage);
  void Reset();
  void Draw();
  void Update();
};

#endif