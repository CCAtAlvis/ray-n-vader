#ifndef game_const
#define game_const
#include "raylib.h"
#include <vector>

class Const {
 public:
  static int screenWidth;
  static int screenHeight;
  static int screenMargin;
  static int score;
  static bool isGameOver;
  static bool isGamePaused;
  static std::vector<Color> enemyStrengthColors;
};

#endif