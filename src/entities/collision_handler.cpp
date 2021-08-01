#include "../headers/collision_handler.h"
#include "enemy.h"
#include "player.h"
#include "raylib.h"
#include "bullet.h"

bool CheckPlayerCollision() {
  for (auto e : Enemy::enemies) {
    Rectangle rec{Player::position.x, Player::position.y,
                  Player::SHIP_HEIGHT + 100, Player::SHIP_WIDTH + 100};
    DrawRectangleLinesEx(rec, 2, RED);
    bool collision = CheckCollisionCircleRec(e.center, e.radius, rec);

    if (collision) {
      Player::TakeHit(20);
      return true;
    }
  }
  return false;
}

bool CheckBulletCollision() {
  for (auto e : Enemy::enemies) {
    for (auto b : Bullet::bulletes) {
      bool collision =
          CheckCollisionCircles(e.center, e.radius, b.center, b.RADIUS);

      if (collision) {
        e.Reset();
        return true;
      }
    }
  }
  return false;
}