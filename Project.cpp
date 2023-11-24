#include <iostream>
#include "MacUILib.h"
#include "objPosArrayList.h"
#include "Player.h"
#include "GameMechs.h"
#include "MacUILib.h"
#include "objPos.h"
#include "Food.h"


using namespace std;

#define DELAY_CONST 100000

bool exitFlag;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);






char input; // Program Input

GameMechs myGame(15, 30);
Player myPlayer(&myGame);
Food food = {3, 3, 'O'};


int sizeX = myGame.getBoardSizeX();
int sizeY = myGame.getBoardSizeY();

objPos myPlayerPos;



char game_board[15][30];





int main(void)
{

    myPlayer.getPlayerPos(myPlayerPos);
    // food.getFoodPos(&foodPos);

    Initialize();

    while(exitFlag == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}

void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();



    
    food.genPos();

    exitFlag = false;
}

void GetInput(void)
{
    
    input = myGame.getInput(); 

    
}

void RunLogic(void)
{
    

    myPlayer.updatePlayerDir(input); // Update Direction

    myPlayer.movePlayer(input); // Update Player Position 
    myPlayer.getPlayerPos(myPlayerPos);


    // Collision Logic
    if(food.x = myPlayerPos.x && food.y = myPlayerPos.y)
    {
        food.genPos();
        // Increase Length
    }

}

void DrawScreen(void)
{
    MacUILib_clearScreen();

    // Populating Game Board Frame
    for (int row = 0; row < sizeX; row++)
    {

        for (int column = 0; column < sizeY; column++)
        {

            if (row == 0 || (row == sizeX - 1 )) // Header and Footer
            {
                game_board[row][column] = '#';
            }

            else if ((column == 0) || (column == sizeY - 1 )) // Sides
            {
                game_board[row][column] = '#';
            }

            else if (row == myPlayerPos.y && column == myPlayerPos.x) // Player Object
            {
                game_board[row][column] = myPlayerPos.symbol;
            }

            // Non Player Objects
            
            else if (row == food.y && column == food.x) // Player Object
            {
                game_board[row][column] = food.symbol;
            }


            else // Non Active
            {
                game_board[row][column] = ' ';
            }
        }
    }



    for (int row = 0; row < sizeX; row++)
    {

        for (int column = 0; column < sizeY; column++)
        {

            MacUILib_printf("%c", game_board[row][column]);
        }

        MacUILib_printf("\n");
    }


    // Display Information

    // printf("%c\n", input);
    printf("%d\n", myPlayerPos.x);
    printf("%d\n", myPlayerPos.y);
        
        MacUILib_printf("\n");



}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
  
    MacUILib_uninit();
}
