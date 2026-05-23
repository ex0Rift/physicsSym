//
//Made by Nate on 22/05/2026
//
//WE ARE SO BACK BABY IM CODING
//p.s im doing this in a car
//


#include <iostream>
#include <vector>
#include "raylib.h"
#include "cube.hpp"
#include "constants.hpp"

std::vector<Cube> cubes;

int main()
{   
    //initialise the window
    InitWindow(screenWidth,screenHeight,"Physics fun");
    SetTargetFPS(60);

    //mainloop
    while (!WindowShouldClose())
    {
        //per frame logic

        //get current mouse pos
        Vector2 mousePos = GetMousePosition();

        if (IsKeyPressed(KEY_ONE))
        {
            Cube latestCube = Cube({mousePos.x,mousePos.y},20.0f,BLUE);
            cubes.push_back(latestCube);
        }

        //draw to the screen
        BeginDrawing();

        ClearBackground(WHITE);

        if (!cubes.empty())
        {
            for (Cube i : cubes)
            {
                i.Draw();
            }
        }

        EndDrawing();
    }
    //close condition

    CloseWindow();
    return 0;
}