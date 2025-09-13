#include "block.hpp"

Block::Block(): CellSize(30), RotationState(0), RowOffset(0), ColumnOffset(0), Colors (GetCellColors()) {};

void Block::Draw(int OffsetX, int OffsetY) {
    std::vector<Position> Tiles = GetCellPositions();
    for (Position i: Tiles) {
        DrawRectangle(i.Column*CellSize+OffsetX, i.Row*CellSize+OffsetY, CellSize-1, CellSize-1, Colors[ID]);
    }
}

void Block::Move(int rows, int columns) {
    RowOffset += rows;
    ColumnOffset += columns;
}

std::vector<Position> Block::GetCellPositions() {
    std::vector<Position> Tiles = Cells[RotationState];
    std::vector<Position> MovedTiles;
    for (Position i : Tiles) {
        Position NewPosition = Position(i.Row + RowOffset, i.Column + ColumnOffset);
        MovedTiles.push_back(NewPosition);
    }
    return MovedTiles;
}

void Block::Rotate() {
    RotationState ++;
    if (RotationState == (int)Cells.size()) {
        RotationState = 0;
    }
}

void Block::UndoRotate() {
    RotationState--;
    if (RotationState == -1) {
        RotationState = Cells.size() - 1;
    }
}