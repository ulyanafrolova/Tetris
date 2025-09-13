#include "game.hpp"

Game::Game(): Blocks(GetAllBlocks()), Current(GetRandomBlock()), Next(GetRandomBlock()), grid(Grid()), IsGameOver(false), Score(0) {};

Block Game::GetRandomBlock() {
    if (Blocks.empty()) {
        Blocks = GetAllBlocks();
    }
    int RandomIndex = rand() % Blocks.size();
    Block block = Blocks[RandomIndex];
    Blocks.erase(Blocks.begin() + RandomIndex);
    return block;
}

std::vector<Block> Game::GetAllBlocks() {
    return {IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
}

void Game::Draw() {
    grid.Draw();
    Current.Draw(11, 11);
    switch(Next.ID) {
        case 1:
        Next.Draw(255, 290);
        break;
        case 4:
        Next.Draw(255, 280);
        break;
        default:
        Next.Draw(270, 270);
        break;
    }
}

void Game::HandleInput() {
    int KeyPressed = GetKeyPressed();  // getting the key that user prossed
    if (IsGameOver && KeyPressed != 0) {
        IsGameOver = false;
        ResetGame();
    }
    switch(KeyPressed) {
        case KEY_LEFT:
        MoveBlockLeft();
        break;
        case KEY_RIGHT:
        MoveBlockRight();
        break;
        case KEY_DOWN:
        MoveBlockDown();
        UpdateScore(0, 1);
        break;
        case KEY_UP:
        RotateBlock();
        break;
    }
}

void Game::MoveBlockLeft() {
    if(!IsGameOver) {
        Current.Move(0,-1);
        if (IsBlockOutside() || IfBlockFits() == false) Current.Move(0,1);
    }
}

void Game::MoveBlockRight() {
    if (!IsGameOver) {
        Current.Move(0,1);
        if (IsBlockOutside() || IfBlockFits() == false) Current.Move(0,-1);
    }
}

void Game::MoveBlockDown() {
    if (!IsGameOver){
        Current.Move(1,0);
        if (IsBlockOutside() || IfBlockFits() == 0) {
            Current.Move(-1,0);
            LockBlock();
        }
    }
}

bool Game::IsBlockOutside() {
    std::vector<Position> tiles = Current.GetCellPositions();
    for (Position i : tiles) {
        if (grid.IsCellOutside(i.Row, i.Column)) return true;
    }
    return false;
}

void Game::RotateBlock() {
    Current.Rotate();
    if (IsBlockOutside() || IfBlockFits() == false) {
        Current.UndoRotate();
    }
}

void Game::LockBlock() {
    std::vector<Position> tiles = Current.GetCellPositions();
    for (Position i: tiles) {
        grid.GridForTest[i.Row][i.Column] = Current.ID;
    }
    Current = Next;
    if (IfBlockFits() == false) {
        IsGameOver = true;
    }
    Next = GetRandomBlock();
    int ClearedRows = grid.ClearFullRows();
    UpdateScore(ClearedRows, 0);
}

bool Game::IfBlockFits() {
    std::vector<Position> tiles = Current.GetCellPositions();
    for (Position i: tiles) {
        if (grid.IsCellEmpty(i.Row, i.Column) == false) return false;
    }
    return true;
}

void Game::ResetGame() {
    grid.Initialize();
    Blocks = GetAllBlocks();
    Current = GetRandomBlock();
    Next = GetRandomBlock();
    Score = 0;
}

void Game::UpdateScore(int ClearedLines, int PlacedBlocks) {
    switch (ClearedLines) {
        case 1:
        Score += 100;
        break;
        case 2:
        Score += 200;
        break;
        case 3:
        Score += 300;
        break;
        default:
        break;
    }
    Score += PlacedBlocks;
}
