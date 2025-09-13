#pragma once
#include <map>
#include <vector>
#include "position.hpp"
#include "colors.hpp"

class Block {

    private:
    int CellSize;
    int RotationState;
    int RowOffset;
    int ColumnOffset;
    std::vector<Color> Colors;

    public:
    Block();
    int ID;
    std::map<int, std::vector<Position>> Cells;
    void Draw(int OffsetX, int OffsetY);
    void Move(int rows, int columns);
    std::vector<Position> GetCellPositions();
    void Rotate();
    void UndoRotate();
};