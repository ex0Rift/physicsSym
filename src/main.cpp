//
//Made by Nate on 22/05/2026
//
//WE ARE SO BACK BABY IM CODING
//p.s im doing this in a car
//


#include <iostream>
#include "raylib.h"
#include "cube.hpp"


int main()
{   
    //initialise the window
    InitWindow(1200,800,"Physics fun");
    SetTargetFPS(60);

    Cube cube1 = Cube({12.0f,12.0f},50.0f);


    //mainloop
    while (!WindowShouldClose())
    {
        //draw to the screen
        BeginDrawing();

        ClearBackground(WHITE);

        cube1.Draw();

        EndDrawing();
    }
    //close condition

    return 0;
}