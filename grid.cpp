#include "grid.hpp"

Grid::Grid() {
    Rows=20;
    Columns=10;
    CellSize=30;
    Initialize();
    Colors = GetCellColors();
}

void Grid::Initialize() {
    for (int i=0; i<Rows; ++i) {
        for (int j=0; j<Columns; ++j) {
            GridForTest[i][j] = 0;
        }
    }
}

void Grid::Print() {
    for (int i=0; i<Rows; ++i) {
        for (int j=0; j<Columns; ++j) {
            std::cout << GridForTest[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void Grid::Draw() {
    for (int i=0; i<Rows; ++i) {
        for (int j=0; j<Columns; ++j) {
            int CellValue = GridForTest[i][j];
            DrawRectangle(j * CellSize+11, i * CellSize+11, CellSize-1, CellSize-1, Colors[CellValue]);
        }
    }
}

bool Grid::IsCellOutside(int row, int column) {
    if (row>=0 && row<Rows && column>=0 && column<Columns) {
        return false;
    }
    return true;
}

bool Grid::IsCellEmpty(int row, int column) {
    if (GridForTest[row][column] == 0) return true;
    return false;
}

int Grid::ClearFullRows() {
    int Completed = 0;
    for(int i=Rows-1; i>=0; --i) {
        if (IsRowFull(i)) {
            ClearRow(i);
            Completed++;
        }
        else if (Completed>0) MoveRowDown(i, Completed);
    }
    return Completed;
}

bool Grid::IsRowFull(int row) {
    for (int j=0; j<Columns; ++j) {
        if (GridForTest[row][j] == 0) return false;
    }
    return true;
}

void Grid::ClearRow(int row) {
    for (int j=0; j<Columns; ++j) {
        GridForTest[row][j] = 0;
    }
}

void Grid::MoveRowDown(int row, int numR) {
    for (int j=0; j<Columns; ++j) {
        GridForTest[row+numR][j] = GridForTest[row][j];
        GridForTest[row][j] = 0;
    }
}