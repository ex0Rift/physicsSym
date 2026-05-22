#pragma once
#include "raylib.h"


class Cube
{
private:
    Vector2 position;
    float size;

public:
    Cube(Vector2 startPos, float initsize);
    bool Draw();

};
