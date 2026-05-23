#pragma once
#include "raylib.h"


class Cube
{
private:
    Vector2 position;
    float size;
    Color color;
    bool inAir;

public:
    Cube(Vector2 startPos, float initsize, Color inColor);
    void Draw();
    void Collide();

};
