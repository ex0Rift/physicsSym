#pragma once
#include "raylib.h"


class Cube
{
private:
    Vector2 position;
    float size;
    Color color;
    bool inAir;
    float velocity;

public:
    Cube(Vector2 startPos, float initsize, Color inColor);
    void Draw();
    void Move(Vector2 change);
    void Fall();
    void Collide();

};
