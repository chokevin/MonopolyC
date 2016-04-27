#include <iostream>
#include <string>

#define MAXSIZE 40

class Player{

public:
   
/* Constructor and Deconstructor */
    
    Player(std::string Name, int Number, int Cash = 1500, int Position = 0);
    ~Player();

/* Accessor Functions 
 * 
 * These are the functions that are used to access the private information
 * that the Player class stores.
 *
*/ 
    std::string player_getName();
    int player_getNumber();
    int player_getCash();
    int player_getPosition();
/* Manipulator Functions
 *
 * These are the functions that are used to manipulate the private variables stored
 * by the player class 
 *
*/
   
    void player_editName(std::string Name);
    void player_editNumber(int Number);
    void player_editCash(int Cash);
   

private:
    void init_to_empty(); 
    std::string name;
    int number;
    int cash;
    int position;
    
};

