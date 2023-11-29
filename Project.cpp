#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "GameMechs.h"
#include "Player.h"



using namespace std;

#define DELAY_CONST 100000



char input; // Program Input

GameMechs myGame(15, 30);
objPosArrayList body;

Player myPlayer(&myGame, &body);



objPosArrayList*& bodyRef = myPlayer.getPlayerPos(); //Reference to Body


int sizeX = myGame.getBoardSizeX(); 
int sizeY = myGame.getBoardSizeY();



objPos myFoodPos;



char game_board[15][30];



bool exitFlag;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



objPos head;



int main(void)
{

    

    // objPos head(10, 8, '*');

    // body.insertTail(head);

    // objPosArrayList*& bodyRef = myPlayer.getPlayerPos(); //Reference to Body

    myPlayer.generateFood();

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



    exitFlag = false;
}

void GetInput(void)
{
    
    input = myGame.getInput(); 

    
}

void RunLogic(void)
{
    // Food Generated

    myPlayer.getFoodPos(myFoodPos); // Update Food Position


    myPlayer.updatePlayerDir(input); // Update Direction


    myPlayer.movePlayer(input); // Update Player Position 
    

    myPlayer.getFoodPos(myFoodPos); // Update Food Position

    body = *bodyRef;


    // // Collision Logic

    // body.getHeadElement(head);

    // if(myFoodPos.x == head.x && myFoodPos.y == head.y)
    // {
        
              
        
    //     myPlayer.generateFood();
    //     myPlayer.getFoodPos(myFoodPos);



    // }



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


            // Non Player Objects
            
            else if (row == myFoodPos.y && column == myFoodPos.x) // Player Object
            {
                game_board[row][column] = myFoodPos.symbol;
            }


            else // Non Active
            {
                game_board[row][column] = ' ';
            }

            // Accessing Player Body

            
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



    for (int row = 0; row < sizeX; row++)
    {

        for (int column = 0; column < sizeY; column++)
        {

            MacUILib_printf("%c", game_board[row][column]);
        }

        MacUILib_printf("\n");
    }


    // Display Information

    printf("%c\n", input);
    printf("%d\n", body.getSize()-1); // Score
        
        MacUILib_printf("\n");

     MacUILib_printf("Food: \n");
    printf("%d\n", myFoodPos.x);
    printf("%d\n", myFoodPos.y);

     MacUILib_printf("Head: \n");
    printf("%d\n", head.x);
    printf("%d\n", head.y);





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
