#include <iostream>
#include <vector>
#include <string>
#define MAXSIZE 40

using namespace std;
class Player;
class Property;

class Game{

public:
    void init_game();

/* This function rolls the dice and returns the amount of space the player moves 
   It uses the sleep function in order to offset the random function that uses the
   the time variable for randomness.*/
    int roll_dice();

    void menu();   
    void selection(char Action); 

    /* Function initializes trading between players. */
    void init_trade();
    
    /* Functions that deal with accessing information about property tiles */
    void buyhouse();
    void sellhouse();
    void moveplayer();
    bool buyproperty();
    void auctionproperty();
    bool bidproperty(int player);
    
private: 
    vector<Player> players;
    vector <Property> board;
    int turn;
    int dice1;
    int dice2; 
    int counter;
    int auctionmoney;

};

