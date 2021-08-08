#ifndef player
#define player

#include "raylib.h"

class Player {
 private:
  static const int TURRET_SIZE = 20;
  static const int TURRET_TRANSLATION = 9;
  static constexpr float PLAYER_SPEED = 2.0;

 public:
  static const int SHIP_HEIGHT = 20;
  static const int SHIP_WIDTH = 20;
  static Vector2 position;
  static Vector2 speed;
  static float acceleration;
  static float rotation;
  static Color playerColor;
  static Color turretColor;
  static int life;

  static void Init();
  static void Draw();
  static void Update();
  static void KeyboardUpdate();
  static void ControllerUpdate();
  static void TakeDamage(int damage);
};

#endif