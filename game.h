#include <iostream>
#include <vector>
#include <string>
#include "property.h"
#define MAXSIZE 40

class Player;

class Game{

public:
    void init_game();
    
/* This function rolls the dice and returns the amount of space the player moves */
    int roll_dice();
    
    void init_trade();
    
    
private: 
    std::vector<Player> players;
    Property board[MAXSIZE];
    int dice1;
    int dice2; 
    int counter;
};

