#ifndef enemy
#define enemy

#include <vector>

#include "../headers/game.h"
#include "player.h"
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