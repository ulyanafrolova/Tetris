#pragma once
#include "grid.hpp"
#include "blocks.hpp"
#include <random>

class Game {
    private:
    std::vector<Block> Blocks;
    Block Current;
    Block Next;
    void RotateBlock();
    void LockBlock();
    void ResetGame();
    void UpdateScore(int ClearedLines, int PlacedBlocks);
    Block GetRandomBlock();
    std::vector<Block> GetAllBlocks();
    void MoveBlockLeft();
    void MoveBlockRight();
    Grid grid;

    public:
    Game();
    void Draw();
    void HandleInput();
    void MoveBlockDown();
    bool IsBlockOutside();
    bool IfBlockFits();
    bool IsGameOver;
    int Score;
};