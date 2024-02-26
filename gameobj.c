#include "gameobj.h"

void UpdatePlatform(Platform *platform)
{
    platform->rect.y += platform->speed;

    if (platform->rect.y + platform->rect.height > WINDOW_HEIGHT)
    {
        platform->rect.y = WINDOW_HEIGHT - platform->rect.height;
    }

    if (platform->rect.y < 0)
    {
        platform->rect.y = 0;
    }
}

void UpdateEnemyAI(Platform *enemy, Ball *ball)
{
    enemy->speed = ball->position.y > enemy->rect.y + enemy->rect.height / 2 ? PLATFORM_SPEED : -PLATFORM_SPEED;
}

void UpdateBall(Ball *ball)
{
    ball->position.x += ball->speed.x;
    ball->position.y += ball->speed.y;

    if (ball->position.y + ball->radius > WINDOW_HEIGHT || ball->position.y - ball->radius < 0)
    {
        ball->speed.y *= -1;
    }

    if (ball->position.x + ball->radius > WINDOW_WIDTH || ball->position.x - ball->radius < 0)
    {
        ball->speed.x *= -1;
    }
}