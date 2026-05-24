#pragma once
#include "raylib.h"


class Cube
{
private:
    Vector2 position;
    float size;
    Color color;
    bool inAir;
    Vector2 velocity;

public:
    Cube(Vector2 startPos, float initsize, Color inColor);
    Vector2 GetPosition();
    float GetSize();
    void Draw();
    void Move(Vector2 change);
    void Place(Vector2 newPosition);
    void Fall();
    void Collide();
    void GiveVelocity(Vector2 addedVelocity);
   

};
