#pragma once
#include <iostream>
#include <vector>
#include <raylib.h>
#include "colors.hpp"

class Grid {
    private:

    int Rows;
    int Columns;
    int CellSize;
    std::vector<Color> Colors;
    bool IsRowFull(int row);
    void ClearRow(int row);
    void MoveRowDown(int row, int Rows);

    public:

    int GridForTest[20][10];
    Grid();
    void Initialize();
    void Print();
    void Draw();
    bool IsCellOutside(int row, int column);
    bool IsCellEmpty(int row, int column);
    int ClearFullRows();
};