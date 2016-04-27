#include <iostream>
#include <string>

#define MAXSIZE 40
using namespace std;

class Player{

public:
   
/* Constructor and Deconstructor */
    
    Player(string Name, int Number, int Cash = 1500, int Position = 0);
    ~Player();

/* Accessor Functions 
 * 
 * These are the functions that are used to access the private information
 * that the Player class stores.
 *
*/ 
    string player_getName();
    int getNumber();
    int getCash();
    int getPosition();
/* Manipulator Functions
 *
 * These are the functions that are used to manipulate the private variables stored
 * by the player class 
 *
*/
   
    void editName(string Name);
    void editNumber(int Number);
    void editCash(int Cash);
   

private:
    void init_to_empty(); 
    string name;
    int number;
    int cash;
    int position;
    
};

