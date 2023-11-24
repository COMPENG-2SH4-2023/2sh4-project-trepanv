#include "Player.h"
#include "GameMechs.h"
#include "MacUILib.h"
#include "objPos.h"



Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    
    playerPos.setObjPos(5, 5, '*');

}


Player::~Player()
{
    // delete any heap members here
}

void Player::getPlayerPos(objPos &returnPos)
{
    // return the reference to the playerPos arrray list
    returnPos.x =  playerPos.x;
    returnPos.y =  playerPos.y;
    returnPos.symbol =  playerPos.symbol;


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
            playerPos.y -= 1;

            if (playerPos.y == 0)
            {
                playerPos.y = 14;
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
            playerPos.y += 1;


            if (playerPos.y == 14)
            {
                playerPos.y = 1;
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
            playerPos.x -= 1;

            if (playerPos.x == 0)
            {
                playerPos.x = 28;
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
            playerPos.x += 1;


            if (playerPos.x == 29)
            {
                playerPos.x = 1;
            }

        }
        break;

    default:
        break;
    }




    oldDir = myDir;

}
