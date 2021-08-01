#include "../headers/collision_handler.h"
#include "enemy.h"
#include "player.h"
#include "raylib.h"


bool CheckCollision() {
  for (auto e : Enemy::enemies) {
      Vector2 center = e.center;
      float radius = radius;
      Rectangle rec{Player::position.x, Player::position.y, Player::SHIP_HEIGHT, Player::SHIP_WIDTH};
    bool collision =
        CheckCollisionCircleRec(center, radius, rec);
        if(collision) return true;
  }
  return false;
}