#include "GameMechs.h"
#include "MacUILib.h"


GameMechs::GameMechs()
{
    // Initial Conditions of Game Baord
    
    boardSizeX = 30;
    boardSizeY = 15;
    
    input = 0;
    exitFlag = false;

    score = 0;

}

GameMechs::GameMechs(int boardX, int boardY)
{
    boardSizeX = boardX;
    boardSizeY = boardY;

    input = 0;
    exitFlag = false;
}


bool GameMechs::getExitFlagStatus()
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus()
{
    return loseFlag;
}



char GameMechs::getInput()
{
    if (MacUILib_hasChar() != 0) // Checking for INput Character
    {
        return MacUILib_getChar(); // Storing Input Character
    }

    else
    {
        return 0;
    }
}

int GameMechs::getBoardSizeX()
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY()
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::setLoseTrue()
{
    loseFlag = true;
}


void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = 0;
}

int GameMechs::getScore()
{
    return score;
}

void GameMechs::incrementScore()
{
    score += 1;

}


