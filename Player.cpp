#include "Player.h"
#include "GameMechs.h"
#include "MacUILib.h"
#include "objPosArrayList.h"


#include <cstdlib>
#include <ctime>

Player::Player(GameMechs* thisGMRef, objPosArrayList* snake)
{
    // Default Player Conditions
    
    mainGameMechsRef = thisGMRef;
    body = snake;
    myDir = STOP;


    objPos head = {15, 8, '*'};
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
        case '\x1B': // exit
            mainGameMechsRef->setLoseTrue();
            mainGameMechsRef->setExitTrue();
            break;

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
            
            curPos.y -= 1; // Updating Position

            if (curPos.y == 0) // Wrap Around
            {
                curPos.y = 13;
            }

                        
            // Collission Logic
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

            // Sekf Collission Check
            if(checkSelfCollision() == 1)
            {
                mainGameMechsRef->setLoseTrue();
                mainGameMechsRef->setExitTrue();
            }


        }
        

        
        break;


    case DOWN: // moving DOWN

        if (oldDir == UP)
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


            if(checkSelfCollision() == 1)
            {
                mainGameMechsRef->setLoseTrue();
                mainGameMechsRef->setExitTrue();
            }


        }

        

        break;

    case LEFT: // moving LEFT

        if (oldDir == RIGHT)
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

            if(checkSelfCollision() == 1)
            {
                mainGameMechsRef->setLoseTrue();
                mainGameMechsRef->setExitTrue();

            }


        }

        break;

    case RIGHT: // moving RIGHT

        if (oldDir == LEFT)
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

            if(checkSelfCollision() == 1)
            {
                mainGameMechsRef->setLoseTrue();
                mainGameMechsRef->setExitTrue();
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

    //Initialisations
    int valid = 0;
    int sizeX = mainGameMechsRef->getBoardSizeX();
    int sizeY = mainGameMechsRef->getBoardSizeY();
    std::srand(std::time(0));



    while(valid == 0)
    {
        foodPos.x = 1 + std::rand() % (sizeY - 2 - 1 + 1); // Random Generation 
        foodPos.y = 1 + std::rand() % (sizeX - 2 - 1 + 1);

        bool collision = false;

        for (int i = 0; i < body->getSize(); ++i) // Indexing through Body to Prevent Body Generations
        {
            objPos currentPos;
            body->getElement(currentPos, i);

            if (foodPos.y == currentPos.y && foodPos.x == currentPos.x) // Check for collision with player body
            {
                collision = true;
                break;
            }
        }

        if (!collision) {
            valid = 1; // No collision found, set valid to 1 to exit the loop
        }

    }
    
    foodPos.symbol = 'o';

}


void Player::getFoodPos(objPos &returnPos)
{

    returnPos.x = foodPos.x;
    returnPos.y = foodPos.y;
    returnPos.symbol = foodPos.symbol;

}


int Player::checkSelfCollision()
{

    // Accessing Body Parts

    objPos headPos;
    objPos bodyPos;
    int size = body->getSize();
    
    body->getHeadElement(headPos);
    
    
    for(int i =1; i < size; i++)
    {
        body->getElement(bodyPos, i);

        if(headPos.x == bodyPos.x && headPos.y == bodyPos.y)
        {
            return 1;
        }
    }

    return 0;


}

