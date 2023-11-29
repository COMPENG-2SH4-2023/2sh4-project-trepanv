#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"

class Player
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  // This is the direction state


        Player(GameMechs* thisGMRef, objPosArrayList* snake);
        ~Player();

        objPosArrayList*& getPlayerPos(); // Upgrade this in iteration 3.
        void updatePlayerDir(char input);
        void movePlayer(char input);

        void generateFood();
        void getFoodPos(objPos &returnPos);


        
    private:
        objPosArrayList* body;   // Upgrade this in iteration 3.       
        objPos foodPos;
        
        enum Dir myDir;
        enum Dir oldDir;


        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef;
        


};

#endif