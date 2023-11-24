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


        Player(GameMechs* thisGMRef);
        ~Player();

        void getPlayerPos(objPos &returnPos); // Upgrade this in iteration 3.
        void updatePlayerDir(char input);
        void movePlayer(char input);

        // void dir_log();
        
    private:
        objPos playerPos;   // Upgrade this in iteration 3.       
        enum Dir myDir;
        enum Dir oldDir;
        
        int dir_tracker[2]; // Direction Tracker = [new, old]
        int old_DIR;

        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef;
        


};

#endif