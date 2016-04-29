#include <iostream>
#include <vector>
#include <string>
#define MAXSIZE 40

using namespace std;
class Player;
class Property;

class Game{

public:
    
    Game();
    ~Game();

    void init_game();

/* This function rolls the dice and returns the amount of space the player moves 
   It uses the sleep function in order to offset the random function that uses the
   the time variable for randomness.*/
    int roll_dice();

    void menu();   
    void selection(char Action); 

    /* Function initializes trading between players. */
    void init_trade();
    void init_board();
    
    /* Functions that deal with accessing information about property tiles */
    void buyhouse();
    void sellhouse();
    void moveplayer();
    void displaymoney();
    bool buyproperty();
    bool buyrailroad();
    bool buyutility();
    void auctionproperty();
    void checkproperties();
    bool bidproperty(int player);
    void jailcheck();
    int checkrailroads();

    /* Functions which indicate what actions to take when landing on a specific tile */
    void propertytile();
    void railroadtile();
    void utilitytile();
    void jailtile();
    void parkingtile();
    void chancetile();
    void chesttile();
    void gotojail();
    void maketrade();


    
private: 
    void init_to_empty();
    vector<Player> players;
    vector <Property> board;
    int turn;
    int dice1;
    int dice2; 
    int counter;
    int auctionmoney;
    int tax;

};

void makeline();

