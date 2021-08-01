#include <math.h>
#include <vector>

#include "raylib.h"

#include "../headers/bullet.h"
#include "../headers/player.h"

class Bullet
{
private:
    static std::vector<Bullet> bullets;
    static const int BULLET_WIDTH = 4;
    static const int BULLET_HEIGHT = 10;

public:
    Vector2 p1, p2, p3, p4;
    Vector2 direction;
    float speed;
    float rotation;

    Bullet() {}

    void draw()
    {
    }

    void update()
    {
    }

    static void Init()
    {
        for (int i = 0; i < 30; ++i)
        {
            Bullet b;
            bullets.push_back(b);
        }
    }

    static void Spawn() {
        // rotate
        Bullet b = bullets[1];
        float pSin = sin(Player::rotation * DEG2RAD);
        float pCos = cos(Player::rotation * DEG2RAD);

        // bullet direction
        b.direction.x = pSin;
        b.direction.y = pCos;

        // bullet's 4 vertices
        Vector2 v1 = {Player::position.x - pCos * (BULLET_WIDTH / 2), Player::position.y + pSin * (BULLET_HEIGHT / 2)};

        Vector2 v2 = {Player::position.x + pCos * (BULLET_WIDTH / 2), Player::position.y - pSin * (BULLET_HEIGHT / 2)};
        Vector2 v3 = {Player::position.x - pCos * (BULLET_WIDTH / 2), Player::position.y - pCos * (BULLET_HEIGHT)};

        Vector2 v4 = {Player::position.x + pCos * (BULLET_WIDTH / 2), Player::position.y + pSin * (BULLET_HEIGHT / 2)};

    }
};

int main()
{
    int screenWidth = 600;
    int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "test game");
    if (!IsWindowFullscreen())
        ToggleFullscreen();

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        ClearBackground(RAYWHITE);
        BeginDrawing();

        for (int i = 0; i < 30; ++i)
        {
         
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
