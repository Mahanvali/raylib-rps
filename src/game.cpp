#include "game.hpp"
#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "../../raygui.h"

int player1 = 0;
int player2 = 0;

bool player1round = true;
bool player2round = false;

bool player1haswon = false;
bool player2haswon = false;
bool tie = false;

bool newturn = false;
bool gameOn = true;

void Game::Draw()
{
    if(player1round){
        DrawText("Player1's turn", 120, 0, 20, RED);
    } else if(player2round){
        DrawText("Player2's turn", 120, 0, 20, RED);
    }

    if(player1haswon){
        DrawText("Player1 has won!", 120, 150, 20, RED);
    }else if(player2haswon){
        DrawText("Player2 has won!", 120, 150, 20, RED);
    }else if(tie){
        DrawText("The game was a tie!", 100, 150, 20, RED);
    }

    ClearBackground(RAYWHITE);
}

void Game::Update()
{
    if(player1round || player2round){
        Rectangle RockRec = {150, 80, 100, 40};
        if(GuiButton(RockRec, "Rock")){
            if(player1round){
                player1 = 1; //1 For Rock
                player1round = false;
                player2round = true;
            } else if(player2round){
                player2 = 1; //1 For Rock
                player2round = false;
                newturn = true;
            }
        }
        Rectangle PaperRec = {150, 160, 100, 40};
        if(GuiButton(PaperRec, "Paper")){
            if(player1round){
                player1 = 2; //2 For Paper
                player1round = false;
                player2round = true;
            } else if(player2round){
                player2 = 2; //2 For Paper
                player2round = false;
                newturn = true;
            }
        }
        Rectangle ScissorRec = {150, 240, 100, 40};
        if(GuiButton(ScissorRec, "Scissor")){
            if(player1round){
                player1 = 3; //3 For Scissor
                player1round = false;
                player2round = true;
            } else if(player2round){
                player2 = 3; //3 For Scissor
                player2round = false;
                newturn = true;
            }
        }
    }
    if(newturn){
        if(IsKeyPressed(KEY_ENTER)){
            newturn = false;
            player1round = true;
            player1 = 0;
            player2 = 0;
            player1haswon = false;
            player2haswon = false;
            tie = false;
        }
    }

    //Game function
    if(player1 == 1 && player2 == 2){ //Rock, Paper
        player2haswon = true;
    }else if(player1 == 1 && player2 == 3){ //Rock, Scissor
        player1haswon = true;
    }else if(player1 == 2 && player2 == 1){ //Paper, Rock
        player1haswon = true;
    }else if(player1 == 2 && player2 == 3){// Paper, Scissor
        player2haswon = true;
    }else if(player1 == 3 && player2 == 1){
        player2haswon = true;
    }else if(player1 == 3 && player2 == 2){
        player1haswon = true;
    }

    if(player1 != 0 && player2 != 0){
        if(player1 == player2){
            tie = true;
        }
    }
}
