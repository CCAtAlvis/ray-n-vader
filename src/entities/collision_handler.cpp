#include "../headers/collision_handler.h"
#include "enemy.h"
#include "player.h"
#include "raylib.h"
#include "bullet.h"
#include "../headers/game.h"
#include <iostream>

void CheckPlayerCollision() {
  for (auto &e : Enemy::enemies) {
    Rectangle rec{Player::position.x - Player::SHIP_WIDTH / 2 - 20,
                  Player::position.y - Player::SHIP_HEIGHT / 2 - 20,
                  Player::SHIP_WIDTH + 40, Player::SHIP_HEIGHT + 40};
    DrawRectangleLinesEx(rec, 2, ORANGE);
    bool collision = CheckCollisionCircleRec(e.center, e.radius, rec);

    if (collision) {
      Player::TakeDamage(20);
      e.Reset();
    }
  }
}

void CheckBulletCollision() {
  for (auto &e : Enemy::enemies) {
    for (auto &b : Bullet::bulletes) {
      if (!b.isEnabled) continue;

      bool collision =
          CheckCollisionCircles(e.center, e.radius, b.center, b.RADIUS);

      if (collision) {
        e.TakeDamage(e.unitStrength);
        b.Disable();
        Const::score++;
      }
    }
  }
}