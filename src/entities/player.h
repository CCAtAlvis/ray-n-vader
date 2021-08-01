#ifndef player
#define player

#include "../headers/game.h"
#include "bullet.h"
#include "raylib.h"
#include "raymath.h"

class Player {
 private:
  static const int TURRET_SIZE = 20;
  static const int TURRET_TRANSLATION = 9;
  static constexpr float PLAYER_SPEED = 2.0;

 public:
  static Vector2 position;
  static Vector2 speed;
  static float acceleration;
  static float rotation;
  static const int SHIP_HEIGHT = 20;
  static const int SHIP_WIDTH = 20;
  static Color playerColor;
  static Color turretColor;

  static void Init();

  static void Draw();

  static void Update();
};

Vector2 Player::position = {0, 0};
Vector2 Player::speed = {100, 100};
float Player::acceleration = 0;
float Player::rotation = 0;
Color Player::playerColor = RED;
Color Player::turretColor = BLACK;

#endif