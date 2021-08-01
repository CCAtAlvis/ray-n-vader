#include <stdlib.h>
#include <string.h>

#include "raylib.h"

#include "../headers/game.h"

void ScoreGui() {
  char score[10];
  itoa(Const::score, score, 10);
  char scoreString[17] = "Score: ";
  strcat(scoreString, score);

  DrawText(scoreString, Const::screenWidth / 2 - 100, 100, 40, BLACK);
}

void GameOverGui() {
  if (Const::isGameOver) {
    Const::isGamePaused = true;
    DrawText("Game Over!", Const::screenWidth / 2 - 100,
             Const::screenHeight / 2 - 100, 40, BLACK);

    DrawText("Press [ESC] to quit!", Const::screenWidth / 2 - 100,
             Const::screenHeight / 2 + 100, 20, BLACK);
  }
}