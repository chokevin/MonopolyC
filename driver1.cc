#include <iostream>
#include "player.h"
#include "property.h"
#include "game.h"

int main(){
    int roll;
    Game game;
    /* Initializing Game */
    game.init_game();

    /* checking if roll dice works */
    roll = game.roll_dice();
    std::cout << "The roll is:" << roll << std::endl;

}

