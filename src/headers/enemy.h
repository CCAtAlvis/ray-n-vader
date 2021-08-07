#ifndef enemy
#define enemy

#include <vector>
#include "raylib.h"

class Enemy {
 public:
  float radius;
  Vector2 center;

 public:
  static Enemy enemies[30];

  Enemy();
  Enemy(int i);
  void Reset();
  void Draw();
  void Update();
};

#endif