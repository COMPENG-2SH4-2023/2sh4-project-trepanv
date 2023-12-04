#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "GameMechs.h"
#include "Player.h"



using namespace std;

#define DELAY_CONST 100000



// GLOBAL VARIABLES

char input; // Program Input

GameMechs myGame(15, 30);
objPosArrayList body;
objPos myFoodPos;


Player myPlayer(&myGame, &body);

int sizeX = myGame.getBoardSizeX(); 
int sizeY = myGame.getBoardSizeY();


char game_board[15][30];
bool exitFlag;
bool loseFlag;




// FUNCTION PROTOTYPES

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{


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

    myPlayer.generateFood(); // Initial Random Food Generation

    exitFlag = false;
}

void GetInput(void)
{
    
    input = myGame.getInput(); // Storing Input

    
}

void RunLogic(void)
{

    // Checking Loosing Condition
    loseFlag = myGame.getLoseFlagStatus();
    

    // Update Food Position
    myPlayer.getFoodPos(myFoodPos); 


    // Update Direction
    myPlayer.updatePlayerDir(input); 


    // Update Player Position After Meeting Required Checks
    /* contains collision logic */
    myPlayer.movePlayer(input);  
    






}

void DrawScreen(void)
{
    MacUILib_clearScreen();



    // Populating Game Board
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


            // Accessing Food Items
            
            else if (row == myFoodPos.y && column == myFoodPos.x) // Player Object
            {
                game_board[row][column] = myFoodPos.symbol;
            }


            else // Non Active
            {
                game_board[row][column] = ' ';
            }

            // Accessing Body Items

            
            for (int i = 0; i < body.getSize(); ++i) 
            {                
                objPos currentPos;


                body.getElement(currentPos, i);


                if (row == currentPos.y && column == currentPos.x) // Player Object
                {
                    game_board[row][column] = currentPos.symbol;
                }


            }



        }
    }


    // Printing Game Board 
    for (int row = 0; row < sizeX; row++)
    {

        for (int column = 0; column < sizeY; column++)
        {

            MacUILib_printf("%c", game_board[row][column]);
        }

        MacUILib_printf("\n");
    }



    // UI Information

    printf("Score: %d\n", body.getSize()-1); // Score
        
    MacUILib_printf("Board Size: 15 x 30 \n");

 
    
    // Printing Game Loss Condiiton
    if(loseFlag == 1)
    {
        
        exitFlag = myGame.getExitFlagStatus();
        MacUILib_clearScreen();

        MacUILib_printf("Your Score was: %d\n", body.getSize()-1);


    }


}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    
    MacUILib_uninit();
}
