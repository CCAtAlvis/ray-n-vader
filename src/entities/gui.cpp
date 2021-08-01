#include <stdlib.h>
#include <string.h>

#include "raylib.h"

#include "../headers/game.h"

void DrawGui() {
  const int width = 200;
  const int height = 50;
  const int x = Const::screenWidth / 2 - width / 2;
  const int y = Const::screenHeight / 2 - height / 2;

  char score[10];
  itoa(Const::score, score, 10);
  char scoreString[17] = "Score: ";
  strcat(scoreString, score);

  DrawText(scoreString, Const::screenWidth / 2, 100, 40, BLACK);
}