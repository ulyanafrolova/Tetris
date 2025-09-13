#pragma once
#include "raylib.h"
#include <vector>

inline const Color GRID = {224, 204, 193, 255};
inline const Color COLOR1 = {97, 25, 43, 255};
inline const Color COLOR2 = {108, 52, 73, 255};
inline const Color COLOR3 = {109, 58, 54, 255};
inline const Color COLOR4 = {135, 119, 14, 255};
inline const Color COLOR5 = {91, 72, 105, 255};
inline const Color COLOR6 = {86, 64, 69, 255};
inline const Color COLOR7 = {161, 164, 170, 255};

std::vector<Color> GetCellColors();