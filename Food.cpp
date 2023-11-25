#include "Food.h"
#include "objPos.h"
#include "MacUILib.h"
#include "GameMechs.h"



#include<cstdlib>
#include <ctime>

Food::genPos()
{
    // more actions to be included
    std::srand(std::time(0))
    
    Food.x = std::rand()%(boardX-1);
    Food.y = std::rand()%(boardY-1);
}


