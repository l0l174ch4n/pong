#include "gameobj.h"
#include "raylib.h"
#include <stdbool.h>
#include <stdint.h>
#include <sys/types.h>

uint32_t background = 0xFF100505;
uint32_t maincolor = 0xFFFFF0F0;

typedef struct
{
    Platform player;
    Platform enemy;
    Ball ball;
} Game;

Game GameInit()
{
    Game game;
    game.player = CLITERAL(Platform){
        .rect =
            {
                .x = 20,
                .y = 300,
                .width = PLATFORM_WIDTH,
                .height = PLATFORM_HEIGHT,
            },

        .speed = 0,
    };

    game.enemy = CLITERAL(Platform){
        .rect =
            {
                .x = WINDOW_WIDTH - PLATFORM_WIDTH - 20,
                .y = 300,
                .width = PLATFORM_WIDTH,
                .height = PLATFORM_HEIGHT,
            },

        .speed = 0,
    };

    game.ball = CLITERAL(Ball){
        .position = {WINDOW_WIDTH / 2.0, WINDOW_HEIGHT / 2.0},
        .radius = 15,
        .speed = {5, 11},
    };

    return game;
}

void HandleKeys(Platform *player)
{
    if (IsKeyDown(KEY_UP))
    {
        player->speed = -PLATFORM_SPEED;
    }
    if (IsKeyDown(KEY_DOWN))
    {
        player->speed = PLATFORM_SPEED;
    }
    if (IsKeyUp(KEY_UP) && IsKeyUp(KEY_DOWN))
    {
        player->speed = 0;
    }
}

void Render(Game *game)
{
    ClearBackground(HEX_COLOR(background));
    DrawCircleV(game->ball.position, game->ball.radius, HEX_COLOR(maincolor));
    DrawRectangleRec(game->player.rect, HEX_COLOR(maincolor));
    DrawRectangleRec(game->enemy.rect, HEX_COLOR(maincolor));
}

void Update(Game *game)
{
    HandleKeys(&game->player);
    UpdateBall(&game->ball);
    UpdateEnemyAI(&game->enemy, &game->ball);
    UpdatePlatform(&game->enemy);
    UpdatePlatform(&game->player);
}

int main()
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Have fun!");

    Game game = GameInit();

    SetTargetFPS(120);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        Update(&game);
        Render(&game);
        EndDrawing();
    }

    return 0;
}