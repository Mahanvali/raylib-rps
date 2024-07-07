#include "raylib.h"
#include "game.hpp"

const int screenWidth = 400;
const int screenHeight = 400;

Game game;
int main(){
    InitWindow(screenWidth, screenHeight, "rps");
    SetTargetFPS(60);

    while(!WindowShouldClose()){
        game.Update();
        BeginDrawing();
            game.Draw();
        EndDrawing();
    }
}
