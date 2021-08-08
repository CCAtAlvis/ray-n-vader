#include <iostream>

#include "raylib.h"
#include "raymath.h"

#include "../headers/game.h"
#include "../headers/player.h"
#include "../headers/bullet.h"

Vector2 Player::position = {0, 0};
Vector2 Player::speed = {100, 100};
float Player::acceleration = 0;
float Player::rotation = 0;
Color Player::playerColor = RED;
Color Player::turretColor = BLACK;
int Player::life = 100;

void Player::Init() {
  position = {Const::screenWidth / 2.0f,
              Const::screenHeight / 2.0f - SHIP_HEIGHT / 2};
}

void Player::Draw() {
  // rotate
  Vector2 v1 = {position.x + sinf(rotation * DEG2RAD) * (TURRET_SIZE),
                position.y - cosf(rotation * DEG2RAD) * (TURRET_SIZE)};
  Vector2 v2 = {position.x - cosf(rotation * DEG2RAD) * (TURRET_SIZE / 2),
                position.y - sinf(rotation * DEG2RAD) * (TURRET_SIZE / 2)};
  Vector2 v3 = {position.x + cosf(rotation * DEG2RAD) * (TURRET_SIZE / 2),
                position.y + sinf(rotation * DEG2RAD) * (TURRET_SIZE / 2)};

  // translate
  v1.x += sinf(rotation * DEG2RAD) * TURRET_TRANSLATION;
  v2.x += sinf(rotation * DEG2RAD) * TURRET_TRANSLATION;
  v3.x += sinf(rotation * DEG2RAD) * TURRET_TRANSLATION;
  v1.y -= cosf(rotation * DEG2RAD) * TURRET_TRANSLATION;
  v2.y -= cosf(rotation * DEG2RAD) * TURRET_TRANSLATION;
  v3.y -= cosf(rotation * DEG2RAD) * TURRET_TRANSLATION;
  DrawTriangle(v1, v2, v3, playerColor);

  if (IsKeyPressed(KEY_SPACE)) {
    Bullet b(v1, rotation);
  }

  DrawPoly(position, 4, SHIP_HEIGHT, rotation, playerColor);
}

void Player::Update() {
  if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) rotation -= 5;
  if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) rotation += 5;

  if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) {
    if (acceleration < 1) acceleration += 0.04f;
  }

  if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
    if (acceleration > -1) acceleration -= 0.04f;
  }

  speed.x = sinf(rotation * DEG2RAD) * PLAYER_SPEED;
  speed.y = cosf(rotation * DEG2RAD) * PLAYER_SPEED;

  if (position.x > Const::screenWidth - SHIP_WIDTH - Const::screenMargin)
    position.x = Const::screenWidth - SHIP_WIDTH - Const::screenMargin;
  else if (position.x < SHIP_WIDTH + Const::screenMargin)
    position.x = SHIP_WIDTH + Const::screenMargin;

  // std::cout << position.y << "\t" << Const::screenHeight << std::endl;

  if (position.y > Const::screenHeight - SHIP_HEIGHT - Const::screenMargin)
    position.y = Const::screenHeight - SHIP_HEIGHT - Const::screenMargin;
  else if (position.y < SHIP_HEIGHT + Const::screenMargin)
    position.y = SHIP_HEIGHT + Const::screenMargin;

  position.x += (speed.x * acceleration);
  position.y -= (speed.y * acceleration);

  acceleration = Lerp(acceleration, 0, 0.03f);
}

void Player::TakeDamage(int damage) {
  life -= damage;
  if (life <= 0) Const::isGameOver = true;
}
