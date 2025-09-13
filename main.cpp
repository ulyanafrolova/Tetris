#include "raylib.h"
#include "grid.hpp"
#include "blocks.hpp"
#include "game.hpp"
#include <iostream>

double LAST_UPDATE_TIME = 0.0;
bool EventTriggered(double interval) {
    double CurrentTime = GetTime();
    if(CurrentTime - LAST_UPDATE_TIME >= interval) {
        LAST_UPDATE_TIME = CurrentTime;
        return true;
    }
    return false;
}
Color BACKGROUND = {255, 245, 238, 255};

int main() {
    InitWindow(500, 620, "Tetris");
    SetTargetFPS(60); // race per second
    Font font = LoadFontEx("font.ttf", 64, 0, 0);
    Game game = Game();
    while (WindowShouldClose() == false) {
        game.HandleInput();
        if (EventTriggered(0.25)) game.MoveBlockDown();
        BeginDrawing();
        ClearBackground(BACKGROUND);
        DrawTextEx(font, "SCORE", {365, 15}, 38, 2, COLOR1);
        DrawTextEx(font, "NEXT", {370, 175}, 38, 2, COLOR1);
        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, GRID);
        DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, GRID);
        if (game.IsGameOver) DrawTextEx(font, "GAME OVER!", {320, 450}, 38, 2, COLOR1);
        char ScoreText[10];
        snprintf(ScoreText, sizeof(ScoreText), "%d", game.Score);
        Vector2 TextSize = MeasureTextEx(font, ScoreText, 38, 2);
        DrawTextEx(font, ScoreText, {320+(170-TextSize.x)/2, 65}, 38, 2, COLOR1);
        game.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
