#include "objPosArrayList.h"
// #include <iostream>



objPosArrayList::objPosArrayList() : sizeList(0), sizeArray(200) 
{ 
    // Initial sizeArray is set to 10
    aList = new objPos[sizeArray];

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
    
    if (sizeList < sizeArray) 
    {
        for (int i = sizeList; i > 0; --i) {
            aList[i] = aList[i - 1];
        }
        aList[0] = thisPos;
        sizeList++;
    }

}

void objPosArrayList::insertTail(objPos thisPos)
{
    // Pointing to the End of List
    
    if (sizeList < sizeArray) 
    {
        aList[sizeList] = thisPos;
        sizeList++;
    }

}

void objPosArrayList::removeHead()
{
    if (sizeList > 0) 
    {
        for (int i = 0; i < sizeList - 1; ++i) {
            aList[i] = aList[i + 1]; // Reassinging Indexes
        }
        sizeList--;
    }

}

void objPosArrayList::removeTail()
{
    if(sizeList > 0)
    {
        
        sizeList--;
    }

}

void objPosArrayList::getHeadElement(objPos &returnPos)
{
    if (sizeList > 0) 
    {
        returnPos = aList[0];
    }

}

void objPosArrayList::getTailElement(objPos &returnPos)
{
    
    if(sizeList > 0)
    {
    
        returnPos = aList[sizeList - 1];

    }

}

void objPosArrayList::getElement(objPos &returnPos, int index)
{
    if (index >= 0 && index < sizeList) 
    {
        returnPos = aList[index];
    }
}

