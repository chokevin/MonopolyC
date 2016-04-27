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

/* This function rolls the dice and returns the amount of space the player moves */
    int roll_dice();
    void menu();   
    void selection(char Action); 
    void init_trade();
    
    void buyhouse();
    void sellhouse();
    void moveplayer();
    bool buyproperty();
    void auctionproperty();
    
private: 
    vector<Player> players;
    vector <Property> board;
    int turn;
    int dice1;
    int dice2; 
    int counter;
    
};

