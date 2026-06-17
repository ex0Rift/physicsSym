//
//Made by Nate on 22/05/2026
//
//WE ARE SO BACK BABY IM CODING
//p.s im doing this in a car
//


#include <iostream>
#include <vector>
#include <random>
#include "raylib.h"
#include "cube.hpp"
#include "constants.hpp"

std::vector<Cube> cubes;
bool MouseHolding = false;
Cube* heldCube = nullptr;
Vector2 mousePos;

std::vector<Color> colours = {
    DARKGRAY, MAROON, ORANGE, DARKGREEN, DARKBLUE, DARKPURPLE,
    DARKBROWN, GRAY, RED, GOLD, LIME, BLUE, VIOLET, BROWN,
    LIGHTGRAY, PINK, YELLOW, GREEN, SKYBLUE, PURPLE, BEIGE

};

auto randomColour(const std::vector<Color>& colourArray)
{
    static std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<size_t> dist(0,colourArray.size() -1);
    return colourArray[dist(rng)];
}

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
        Vector2 mouseDelta = GetMouseDelta();
        Vector2 mousePos = GetMousePosition();
        //get if mouse is held 
        MouseHolding = IsMouseButtonDown(MOUSE_BUTTON_LEFT);

        //checking if a jey is pressed
        if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
        {
            //creates new cube
            Cube latestCube = Cube({mousePos.x,mousePos.y},60.0f,randomColour(colours));
            //places the cube inside the cube array
            cubes.push_back(latestCube);
        }

        //erase the screen
        if (IsKeyPressed(KEY_BACKSPACE))
        {
            cubes.clear();
        }

        //the first cube can be given acceleration by spamming num 2
        if(!cubes.empty())if (IsKeyPressed(KEY_TWO))cubes[0].GiveVelocity({-30,0});

        //logic for per cube per frame
        for (Cube& i : cubes)
        {   
            //reset cubes own colliding state to none at each new frame
            i.SetBlockColliding(false);

            //if left click is being held logic continues
            if (MouseHolding)
            {   
                //grabs the current cubes position for calculations
                Vector2 iPos = i.GetPosition();
                //if statment stating if mouse is inside of current cube 
                //Also bypasses if cube was held last frame, to prevent dropping
                if 
                (
                    mousePos.x > iPos.x && mousePos.x < iPos.x+i.GetSize() &&
                    mousePos.y > iPos.y && mousePos.y < iPos.y+i.GetSize() ||
                    heldCube == &i
                )
                {
                    //put the cube in the position of the mouse
                    i.Place({mousePos.x-(i.GetSize()/2),mousePos.y-(i.GetSize()/2)});
                    //mark this cube as the one being held
                    heldCube = &i;
                    continue;
                }
            }
            //check for collision with other cubes
            for (Cube& j : cubes)
            {
                //skips if the cube is the same as current cube, if cubes is empty
                if (&j != &i && !cubes.empty())
                {
                    Vector2 jPos = j.GetPosition();
                    float jSize = j.GetSize();
                    bool isColliding = i.ObjectCollide(jPos,jSize);
                    //collision triggered
                    if (isColliding)
                    { 
                        i.SetBlockColliding(true);
                        i.SetVelocity({0,0});
                    }
                }
            }
            //Make cube conform to gravity
            i.Fall();
        }
        
        //if statment is true when cube is no longer held and will clear which cube is held after logic
        if (!MouseHolding && heldCube != nullptr)
        {
            heldCube->GiveVelocity({mouseDelta.x,mouseDelta.y});
            heldCube = nullptr;
        }


        //draw to the screen
        BeginDrawing();
        DrawFPS(0,0);
        DrawText("right click for cube",0,40,20,BLUE);

        ClearBackground(WHITE);
        if (MouseHolding)
        {
            DrawText("Holding",0,20,20,RED);
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