#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include "game.h"
using namespace std;

#define MAXSIZE 40 

void Game :: init_game(){

    cout << "Initializing Game" << endl;
    
    int numplayers;
    
    Property board[MAXSIZE];
    // ID 1 = Property
    // ID 2 = Railroad
    // ID 3 = Utility
    // ID 4 = Go
    // ID 5 = Jail
    // ID 6 = Free Parking
    // ID 7 = Chance
    // ID 8 = Community Chest
    // ID 9 = Tax
    // ID 10 = Go to Jail
    
    board[0].init(4, 0, 0, "Go");
    board[1].init(1, 60, 2, "Mediterranean Ave"); 
    board[2].init(8, 0, 0, "Community Chest");
    board[3].init(1, 60, 4, "Baltic Ave");
    board[4].init(9, 200, 0, "Income Tax");
    board[5].init(2, 200, 0, "Reading Railroad");
    board[6].init(1, 100, 6, "Oriental Ave");
    board[7].init(7, 0, 0, "Chance");
    board[8].init(1, 100, 6, "Vermont Ave");
    board[9].init(1, 120, 8, "Connecticut Ave");
    board[10].init(5, 0, 0, "Jail");
    board[11].init(1, 140, 10, "St. Charles Pl");
    board[12].init(3, 150, 0, "Electric Company");
    board[13].init(1, 140, 10, "States Ave");
    board[14].init(1, 160, 12, "Virginia Ave");
    board[15].init(2, 200, 0, "Pennsylvania Railroad");
    board[16].init(1, 180, 14, "St. James Pl");
    board[17].init(8, 0, 0, "Community Chest");
    board[18].init(1, 180, 14, "Tennessee Ave");
    board[19].init(1, 200, 16, "New York Ave");
    board[20].init(6, 0, 0, "Free Parking");
    board[21].init(1, 220, 18, "Kentucky Ave");
    board[22].init(7, 0, 0, "Chance");
    board[23].init(1, 220, 18, "Indiana Ave");
    board[24].init(1, 240, 20, "Illinois Ave");
    board[25].init(2, 200, 0, "B. & O. Railroad");
    board[26].init(1, 260, 22, "Atlantic Ave");
    board[27].init(1, 260, 22, "Ventnor Ave");
    board[28].init(3, 150, 0, "Water Works");
    board[29].init(1, 280, 24, "Marvin Gardens");
    board[30].init(10, 0, 0, "Go to Jail");
    board[31].init(1, 300, 26, "Pacific Ave");
    board[32].init(1, 300, 26, "North Carolina Ave");
    board[33].init(8, 0, 0, "Community Chest");
    board[34].init(1, 320, 28, "Pennsylvania Ave");
    board[35].init(2, 200, 0, "Short Line Railroad");
    board[36].init(7, 0, 0, "Chance");
    board[37].init(1, 350, 35, "Park Place");
    board[38].init(9, 100, 0, "Luxury Tax");
    board[39].init(1, 400, 50, "Boardwalk");
    
    
    
    cout << "How many players will be playing? (1-4 players):";
    cin >> numplayers;
    players.resize(numplayers);
    
    while(1)
    {
        for //for each player
        //roll dice
        //trade prop
        //buy/sell houses
    }
    
    
}
  
int Game :: roll_dice(){
    srand(time(0));
    dice1 = rand()%6+1;
    dice2 = rand()%6+1;
    cout << "Dice 1 roll:" << dice1 << endl;
    cout << "Dice 2 roll:" << dice2 << endl;
    if(dice1 == dice2){
        counter += 1;
    }
    else{
        counter = 0;
    }
    return dice1+dice2;
}    
