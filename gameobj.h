#ifndef GAMEOBJ_H
#define GAMEOBJ_H
#include "constants.h"
#include "raylib.h"

typedef struct
{
    Rectangle rect;
    float speed;

} Platform;

typedef struct
{
    Vector2 position;
    float radius;
    Vector2 speed;
} Ball;

void UpdatePlatform(Platform *platform);

void UpdateEnemyAI(Platform *enemy, Ball *ball);

void UpdateBall(Ball *ball);

#endif