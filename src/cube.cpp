#include "cube.hpp"
#include "raylib.h"
#include "constants.hpp"

Cube::Cube(Vector2 startPos, float initsize, Color inColor)
{
    position = startPos;
    size = initsize;
    color = inColor;
    inAir = true;
}

void Cube::Draw()
{
    DrawRectangle(position.x, position.y, size, size, color);
}

void Cube::Collide()
{
    if (position.y + size >= screenHeight) inAir = false;
}
