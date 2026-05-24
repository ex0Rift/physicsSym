#include "cube.hpp"
#include "raylib.h"
#include "raymath.h"
#include "constants.hpp"

Cube::Cube(Vector2 startPos, float initsize, Color inColor)
{
    position = startPos;
    size = initsize;
    color = inColor;
    inAir = true;
    velocity = {0.0f,2.0f};
}

Vector2 Cube::GetPosition(){return position;}

float Cube::GetSize(){return size;}

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

void Cube::Place(Vector2 newPosition)
{   
    if 
    (
        newPosition.x < screenWidth && newPosition.y < screenHeight &&
        newPosition.x > 0 && newPosition.y > 0
    )
    {
    position = newPosition;
    }
}

void Cube::Fall()
{
    if (inAir)velocity.y += 1.4f;
    if (velocity.x > 0) velocity.x = Clamp(velocity.x - 1.5f, 0.0f, velocity.x);
    else if (velocity.x < 0) velocity.x = Clamp(velocity.x + 1.3f, velocity.x, 0.0f);
    Move(velocity);
}

void Cube::Collide()
{
    if (position.y + size >= screenHeight)
    {
        inAir = false;
        velocity.y = 0;
        position.y = screenHeight - size;
    }
    else
    {
        inAir = true;
    }
}

void Cube::GiveVelocity(Vector2 addedVelocity)
{
    velocity.x += addedVelocity.x;
    velocity.y += addedVelocity.y;
}
