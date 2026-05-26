#pragma once
#include "raylib.h"


class Cube
{
private:
    struct objectBools {
        bool left;
        bool right;
    };

    Vector2 position;
    float size;
    Color color;
    bool inAir;
    bool blockColliding;
    Vector2 velocity;
    objectBools onWall;

    

public:
    Cube(Vector2 startPos, float initsize, Color inColor);
    Vector2 GetPosition();
    float GetSize();
    void SetBlockColliding(bool setter);
    void Draw();
    void Move(Vector2 change);
    void Place(Vector2 newPosition);
    void Fall();
    void Collide();
    bool ObjectCollide(Vector2 comparison, float comparisonSize);
    void GiveVelocity(Vector2 addedVelocity);
   

};
