#include "cube.hpp"
#include "raylib.h"
#include "constants.hpp"

Cube::Cube(Vector2 startPos, float initsize, Color inColor)
{
    position = startPos;
    size = initsize;
    color = inColor;
    inAir = true;
    velocity = 2.0f;
}

void Cube::Draw()
{
    DrawRectangle(position.x, position.y, size, size, color);
}

void Cube::Move(Vector2 change)
{
    Collide();
    position.x += change.x;
    if (inAir || change.y < 0) position.y += change.y;

}

void Cube::Fall()
{
    if (inAir)velocity += 1.4f;
    Move({0,velocity});
}

void Cube::Collide()
{
    if (position.y + size >= screenHeight)
    {
        inAir = false;
        velocity = 0;
        position.y = screenHeight - size;
    }
}
