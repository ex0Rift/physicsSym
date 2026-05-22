#include "cube.hpp"
#include "raylib.h"

Cube::Cube(Vector2 startPos, float initsize)
{
    position = startPos;
    size = initsize;
}

bool Cube::Draw()
{
    DrawRectangle(position.x, position.y, size, size, BLACK);


    return true;
}
