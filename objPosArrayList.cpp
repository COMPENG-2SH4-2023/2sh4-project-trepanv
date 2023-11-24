#include "objPosArrayList.h"
// #include <iostream>

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{

    // Initialise List Size & Arrary Capacity

    sizeList = 0;
    sizeArray = 200;

    // Heap Allocation

    objPos* aList = new objPos[sizeArray];

    for(int i= 0; i < sizeArray; i++)
    {
        objPos zeroPos; //empty opject
        aList[i] = zeroPos;
    }
}

objPosArrayList::~objPosArrayList()
{
   
   // Deallocation
   
    delete[] aList;
}

int objPosArrayList::getSize()
{
    return sizeList;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    // Pointing to the Beginning of List
    
    aList[0].x = thisPos.x; 
    aList[0].y = thisPos.y; 
    aList[0].symbol = thisPos.symbol; 

    sizeList += 1;

}

void objPosArrayList::insertTail(objPos thisPos)
{
    // Pointing to the End of List
    
    if(sizeList > 0)
    {
        aList[sizeList].x = thisPos.x; 
        aList[sizeList].y = thisPos.y; 
        aList[sizeList].symbol = thisPos.symbol; 

        sizeList += 1;
    }

}

void objPosArrayList::removeHead()
{
    aList[0].symbol = ' '; 

    sizeList -= 1;

}

void objPosArrayList::removeTail()
{
    if(sizeList > 0)
    {
        aList[sizeList].symbol = ' '; 
        sizeList -= 1;
    }

}

void objPosArrayList::getHeadElement(objPos &returnPos)
{
    returnPos.x = aList[0].x;
    returnPos.y = aList[0].y;
    returnPos.symbol = aList[0].symbol;
}

void objPosArrayList::getTailElement(objPos &returnPos)
{
    
    if(sizeList > 0)
    {
    
        returnPos.x = aList[sizeList].x;
        returnPos.y = aList[sizeList].y;
        returnPos.symbol = aList[sizeList].symbol;

    }

}

void objPosArrayList::getElement(objPos &returnPos, int index)
{
    returnPos.x = aList[index].x;
    returnPos.y = aList[index].y;
    returnPos.symbol = aList[index].symbol;

    // Doesnt pass checks?
}


// ADD IF STATEMENTS FOR ERROR HANDLING?