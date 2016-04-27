#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include "game.h"

#define MAXSIZE 40 

void Game :: init_game(){

    std::cout << "Initializing Game" << std::endl;
    board[0].init_property("Go", 0, 0 ,0 );
    board[1].init_property("Mediterranean Avenue", 14, 0, 0 ); 
    
}
  
int Game :: roll_dice(){
    srand(time(0));
    dice1 = rand()%6+1;
    dice2 = rand()%6+1;
    std::cout << "Dice 1 roll:" << dice1 << std::endl;
    std::cout << "Dice 2 roll:" << dice2 << std::endl;
    if(dice1 == dice2){
        counter += 1;
    }
    else{
        counter = 0;
    }
    return dice1+dice2;
}    
