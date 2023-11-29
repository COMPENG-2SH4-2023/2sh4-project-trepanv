#include "Player.h"
#include "GameMechs.h"
#include "MacUILib.h"
#include "objPosArrayList.h"


#include <cstdlib>
#include <ctime>

Player::Player(GameMechs* thisGMRef, objPosArrayList* snake)
{
    mainGameMechsRef = thisGMRef;
    body = snake;

    myDir = STOP;

    // more actions to be included

    objPos head = {10, 8, '*'};
    snake->insertTail(head);

}


Player::~Player()
{
    // delete any heap members here
}

objPosArrayList*& Player::getPlayerPos()
{
    // return the reference to the body
    
    return body;

}

void Player::updatePlayerDir(char input)
{
    // PPA3 input processing logic     


    if (input != 0) // if not null character
    {

        // Assinging Iuput to Direction
        switch (input)
        {
        // case '\x1B': // exi
        //     exitFlag = 1;
        //     break;

        case 'w': // UP
            myDir = UP;
            break;

        case 's': // DOWN
            myDir = DOWN;
            break;

        case 'a': // LEFT
            myDir = LEFT;
            break;

        case 'd': // RIGHT
            myDir = RIGHT;
            break;

        default:
            break;
        }

        input = 0; // Input Reset
    }

}

//try switching direction check to update player direction

void Player::movePlayer(char input)
{
    // PPA3 Finite State Machine logic

    switch (myDir)
    {
    case UP: // moving UP

        if (oldDir == DOWN) // if old direction was down it should go down
        {

            myDir = oldDir;
        }

        else
        {        
        
            objPos curPos;

            // Accessing and Editing Head

            body->getHeadElement(curPos);
            
            curPos.y -= 1;

            if (curPos.y == 0)
            {
                curPos.y = 13;
            }

                        
            // Collision Logic

            if(foodPos.x == curPos.x && foodPos.y == curPos.y)
            {
                

                body->insertHead(curPos);
                generateFood();

            }

            else
            {
                body->insertHead(curPos);
                body->removeTail();

            }


        }


        break;


    case DOWN: // moving DOWN

        if (oldDir == UP) // if old direction was down it should go down
        {

            myDir = oldDir;
        }

        else
        {           
        
            objPos curPos;

            // Accessing and Editing Head

            body->getHeadElement(curPos);
            
            curPos.y += 1;

            if (curPos.y == 14)
            {
                curPos.y = 1;
            }

            // Collision Logic

            if(foodPos.x == curPos.x && foodPos.y == curPos.y)
            {
                

                body->insertHead(curPos);
                generateFood();

            }

            else
            {
                body->insertHead(curPos);
                body->removeTail();
                
            }



        }

        

        break;

    case LEFT: // moving LEFT

        if (oldDir == RIGHT) // if old direction was down it should go down
        {

            myDir = oldDir;
        }

        else
        {        

            objPos curPos;

            // Accessing and Editing Head

            body->getHeadElement(curPos);
            
            curPos.x -= 1;

            if (curPos.x == 0)
            {
                curPos.x = 28;
            }

            // Collision Logic

            if(foodPos.x == curPos.x && foodPos.y == curPos.y)
            {
                

                body->insertHead(curPos);
                generateFood();

            }

            else
            {
                body->insertHead(curPos);
                body->removeTail();
                
            }


        }

        break;

    case RIGHT: // moving RIGHT

        if (oldDir == LEFT) // if old direction was down it should go down
        {

            myDir = oldDir;
        }

        else
        {        

            objPos curPos;

            // Accessing and Editing Head

            body->getHeadElement(curPos);
            
            curPos.x += 1;

            if (curPos.x == 29)
            {
                curPos.x = 1;
            }

            // Collision Logic

            if(foodPos.x == curPos.x && foodPos.y == curPos.y)
            {
                

                body->insertHead(curPos);
                generateFood();

            }

            else
            {
                body->insertHead(curPos);
                body->removeTail();
                
            }


        }
        break;

    default:
        break;
    }




    oldDir = myDir;
    
    




}

void Player::generateFood()
{
    //add generation checks
    
    int sizeX = mainGameMechsRef->getBoardSizeX();
    int sizeY = mainGameMechsRef->getBoardSizeY();

    std::srand(std::time(0));

    foodPos.x = 1 + std::rand() % (sizeY - 2 - 1 + 1);
    foodPos.y = 1 + std::rand() % (sizeX - 2  - 1 + 1);

    foodPos.symbol = 'o';

}


void Player::getFoodPos(objPos &returnPos)
{

    returnPos.x = foodPos.x;
    returnPos.y = foodPos.y;
    returnPos.symbol = foodPos.symbol;

}

