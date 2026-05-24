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
bool MouseHolding = false;

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
        //get if mouse is held 
        MouseHolding = IsMouseButtonDown(MOUSE_BUTTON_LEFT);

        if (IsKeyPressed(KEY_ONE))
        {
            Cube latestCube = Cube({mousePos.x,mousePos.y},60.0f,BLUE);
            cubes.push_back(latestCube);
        }

        for (Cube& i : cubes)
        {   
            if (MouseHolding)
            {   
                Vector2 iPos = i.GetPosition();
                if 
                (
                    mousePos.x > iPos.x && mousePos.x < iPos.x+i.GetSize() &&
                    mousePos.y > iPos.y && mousePos.y < iPos.y+i.GetSize()
                )
                {
                    if (MouseHolding)
                    {
                        i.Place({mousePos.x-(i.GetSize()/2),mousePos.y-(i.GetSize()/2)});
                        continue;
                    }
                }
            }
            i.Fall();
        }

        //draw to the screen
        BeginDrawing();
        DrawFPS(0,0);

        ClearBackground(WHITE);
        if (MouseHolding)
        {
            DrawText("Holding",0,100,40,RED);
        }

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