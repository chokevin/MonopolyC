#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "game.h"
#include "property.h"
#include "player.h"

using namespace std;

#define MAXSIZE 40 


/* As a general rule... the n variable is used find the correct index of which player's turn it is. 
   n+1 is used because although players[0] refers to player 1 we need to display +1 to get the actual player number. index goes from 0-3 | player number goes from 1-4
*/

/* Constructor and deconstructor for the game class */
Game::Game(){
    init_to_empty();
}

Game::~Game(){
    init_to_empty();
}

/* Initializing Functions */
void Game::init_game(){
	board.resize(MAXSIZE);
    cout << "\033[2J\033[1;1H";
    cout << "Initializing Game" << endl;
    makeline();
    
    int numplayers;

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

    
    init_board();
    cout << "How many players will be playing? (1-4 players):";
    cin >> numplayers;
    players.resize(numplayers);
    for(int i = 0; i < numplayers; i++){
    	players[i].editCash(1500);
    }
    
    while(1){
        menu();
    }
    
}
 
void Game::init_board(){

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
    
}

void Game::menu(){
    char Action;
    int n = (turn%players.size());
    
    displayboard();
    jailcheck();
    cout << "It is Player " << (turn%players.size())+1 << "'s turn" << endl;    
    displaymoney();
     
    cout << "You are at position " << players[n].getPosition() << " which is " << board[players[n].getPosition()].getName() << endl;
    makeline();
    cout << "What actions would you like to take?" << endl;
   	cout << "(R)oll the dice" << endl;	
    cout << "(C)heck owned properties" << endl;
	cout << "(T)rade a property" << endl;    
	cout << "(B)uy a house" << endl;    
	cout << "(S)ell a house" << endl;    	
	cout << "(Q)uit" << endl;
	cin >> Action;
	selection(Action);
}


void Game::selection(char Action){
	 while(true){
        switch(Action){
            case 'r':
                cout << "Rolling the Dice" << endl;
                moveplayer();
              	menu();
                break;
            case 't':
                cout << "Trading a Property" << endl;
                init_trade();
                menu();
                break;
            case 'b':
                cout << "Buying a House" << endl;
                buyhouse();
                menu();
                break;
            case 's': 
                cout << "Selling a House" << endl;
                sellhouse();
                menu();
                break;
            case 'c':
                cout << "Owned Properties" << endl;
                checkproperties();
                menu();
                break;
            case 'q':
                exit(1);
                break;
            default : 
                cin >> Action;
                break;
        }
     }

}


void Game::moveplayer(){
	int move;
    cout << "\033[2J\033[1;1H";
	move = roll_dice();
    int n = turn%players.size();
    players[n].editPosition(move);
    int check = board[players[n].getPosition()].getID();
    cout << "Player " << n+1 << " landed on " << board[players[n].getPosition()].getName() << endl;
    if(check == 1){
        
        propertytile();
    }
    else if(check == 2){
       /* This is the code that handles when the player lands on a railroad tile */
        railroadtile();

    }
    else if(check == 3){
        /* This is the code that handles when the player lands on a utility tile */
        utilitytile();
    }
   // else if(check == 4){
        /* This is the code that handles when the player lands on the Go title...?*/
     //   gotile();
    //}
    //else if(check == 5){
        /* This is the code that handles when the player lands on the Jail tile */
      //  jailtile();
   // }
    else if(check == 6){
        /* this is the code that handles when the player lands on the free parking tile */
        parkingtile();
    }
    else if(check == 7){
        /* this is the code that handles when the player lands on the chance tile */
        chancetile();
    }
    else if(check == 8){   
        /* this is the code that handles when the player lands on the community chest tile */
        chesttile();

    }
    else if(check == 9){
        cout << "Lol you landed on some tax bro, but since its the free version of Monopoly just pay us $200" << endl;
        players[n].minusCash(200);

        /* Puts money into the middle for the free parking */
        tax += 200;

    }
    else if(check == 10){
        gotojail();
    } 
    turn++;
}

void Game::init_trade(){
    /*Haven't coded this part yet */
	cout << "Initializing Trade";
    cout << "Who would you like to trade with?" << endl;
    makeline();

    /* Design the while loop to display the choices between players 1 - 4. This varies depending on how many players are playing. */

    cout << "Trading with Player" << endl;
    maketrade();
}

void Game::buyhouse(){
    /* Haven't coded this part yet either */
	cout << "Currently the free version doesn't support buying houses... Support the developers" << endl;
}

void Game::sellhouse(){
    /* Haven't coded this part yet */
    cout << "Currently the free version doesn't support selling houses... Support the developers" << endl;
}

int Game::roll_dice(){
    srand(time(0));
    dice1 = rand()%6+1;
    cout << "Dice 1 roll:" << dice1 << endl;
  	sleep(1);
    dice2 = rand()%6+1;
    cout << "Dice 2 roll:" << dice2 << endl;
    if(dice1 == dice2){
        counter += 1;
    }
    else{
        counter = 0;
    }
    return dice1+dice2;
}    

bool Game::buyproperty(){
    char input;
    int n = (turn%players.size());
    cout << "Buying the property" << endl;
        cout << "Would you like to buy " << board[players[n].getPosition()].getName() << "? (y or n):";
        cin >> input; 
    if( input == 'y'){
        players[n].minusCash(board[players[n].getPosition()].getPrice());
        board[players[n].getPosition()].editOwner(n+1);
        cout << board[players[n].getPosition()].getName() << " was bought by Player " << n+1 << "!" << endl;
        players[n].addproperties();
        return true;
    }
    else if ( input == 'n'){
        return false;
    }
    buyproperty();
    return false;
}

bool Game::buyrailroad(){
        char input;
    int n = (turn%players.size());
    cout << "Buying the railroad" << endl;
        cout << "Would you like to buy " << board[players[n].getPosition()].getName() << "? (y or n):";
        cin >> input; 
    if( input == 'y'){
        players[n].minusCash(board[players[n].getPosition()].getPrice());
        board[players[n].getPosition()].editOwner(n+1);
        cout << board[players[n].getPosition()].getName() << " was bought by Player " << n+1 << "!" << endl;
        players[n].addproperties();
        return true;
    }
    else if ( input == 'n'){
        return false;
    }
    buyrailroad();
    return false;
}

bool Game::buyutility(){
    char input;
    int n = (turn%players.size());
    cout << "Buying the utility" << endl;
        cout << "Would you like to buy " << board[players[n].getPosition()].getName() << "? (y or n):";
        cin >> input; 
    if( input == 'y'){
        players[n].minusCash(board[players[n].getPosition()].getPrice());
        board[players[n].getPosition()].editOwner(n+1);
        cout << board[players[n].getPosition()].getName() << " was bought by Player " << n+1 << "!" << endl;
        players[n].addproperties();
        return true;
    }
    else if ( input == 'n'){
        return false;
    }
    buyutility();
    return false;
}

void Game::auctionproperty(){
    bool flag = false;
    vector<bool> check;
    char choice;
    int i = 0;
    int n = turn%players.size();
    check.resize((players.size()), false);
    cout << "Welcome to the Auction!" << endl;
    makeline();
    while(!flag){
        check[i] = bidproperty(n+i);
        i++;
        if(i == 4){
            i = 0;
        }
        if(check[0] == true && check[1] == true && check[2] == true && check[3] == true){
            flag = true;
        }
    }
    cout << "Winner of this auction is Player " << n+i << "for $" << auctionmoney << endl;
    players[n+i].minusCash(auctionmoney);
    board[players[n].getPosition()].editOwner(n);
    auctionmoney = 0;
}

bool Game::bidproperty(int player){

return true;

}

void Game::checkproperties(){
    int owner;
    int counter = 1;
    int n = turn%players.size();
    cout << "Checking Properties:" << endl;
    makeline();
    for(int i = 0; i < board.size(); i++){
        owner = board[i].getOwner();
        if(owner == n+1){
            cout << "You own: " << counter << ". " << board[i].getName() << endl;
            counter++;
        }
    }
}

void Game::propertytile(){
    int n = turn%players.size();
        /* This is the code to handle when the player lands on a property tile */
    if(board[players[(turn%players.size())].getPosition()].getOwner() == 0){
        bool flag = buyproperty();
        if(!flag){
            //auctionproperty();
        }
    }
    else if(board[players[n].getPosition()].getOwner() != n+1){
        int money = board[players[n].getPosition()].getRent();
        cout << "Player " << board[players[n].getPosition()].getOwner() << " owns this property, you pay him $" << money << endl;     
        players[(board[players[n].getPosition()].getOwner())-1].addCash(money);
        players[n].minusCash(money);
    }
}

void Game::railroadtile(){
        int n = turn%players.size();
        /* This is the code to handle when the player lands on a property tile */
    if(board[players[(turn%players.size())].getPosition()].getOwner() == 0){
        bool flag = buyrailroad();
        if(!flag){
            //auctionproperty();
        }
    }

    else if(board[players[n].getPosition()].getOwner() != n+1){
        int check = checkrailroads();
        int money;
        if(check == 1){
            money = 25;
        }
        if(check == 2){
            money = 50;
        }
        if(check == 3){
            money = 100;
        }
        if(check == 4){
            money = 200;
        }
        players[board[players[n].getPosition()].getOwner()].addCash(money);
        players[n].minusCash(money);
    }
}

void Game::chancetile(){
    
    /* Currently this is the function for chance... new updates have been added to increase the amount of options for chance. 
    The switch statement allows for an easy way to increase the amount of chance cards... */
    
    int choice;
    srand(time(0));
    choice = rand()%5;
    int n = turn%players.size();
    /* This switch statement chooses at random the chance card that is selected for the player that lands on it. This can be either increased
    or decreased very simply by adding more case choices. Currently can be further developed.
    */\

    switch(choice){
        case 0:
            cout << "You landed on Chance!... You get $200!" << endl;
            players[n].addCash(200);
        case 1:
            cout << "You landed on Chance!... You get sent to Jail!" << endl;
            players[n].editPosition(19);
            players[n].editJail(true);
        case 2:
            cout << "You landed on Chance!... You get a free pass to Go! (also $200)" << endl;
            players[n].editPosition(0);
            players[n].addCash(200);
        case 3:
            cout << "You landed on Chance!... move to Reading Railroad" << endl;
            if(players[n].getPosition() > 5){
                players[n].addCash(200);
                players[n].editPosition(5);
            }

        case 4:
            cout << "You landed on Chance!... Nothing happens... Better support the developers for more updates!" << endl;
    }


}

void Game::parkingtile(){

    cout << "You landed on Free Parking!... You can collect the money that has been taken as tax: $" << tax << "!'" << endl;
    players[turn%players.size()].addCash(tax);
    tax = 0;

}

void Game::utilitytile(){
    int n = turn%players.size();
        /* This is the code to handle when the player lands on a property tile */
    if(board[players[(turn%players.size())].getPosition()].getOwner() == 0){
        bool flag = buyutility();
        if(!flag){
            //auctionproperty();
        }
    }

    /* Currently this other half of the conditional is wrong as well... the cash distribution for the utilities have not been factored in yet */
    else if(board[players[n].getPosition()].getOwner() != n+1){
        int money = board[players[n].getPosition()].getRent();
        players[board[players[n].getPosition()].getOwner()].addCash(money);
        players[n].minusCash(money);
    }

}


void Game::gotojail(){
    int n = turn%players.size();
    cout << "Why you breaking the law for! GO TO JAIL PLAYER " << (n+1) << endl;
    players[n].editPosition(10);
    players[n].editJail(true);


}

void Game::jailtile(){
    int n = turn%players.size();
    cout << "It is Player " << (turn%players.size())+1 << "'s turn" << endl;
    cout << "You are on the jail tile" << endl;
    if(players[n].getJail()){
        cout << "You are currently a prisoner... skipping your turn" << endl;
        turn++;
        players[n].editJail(false);
    }
}

void Game::chesttile(){
    
    /*This can be updated to include many other chest cards if we like */

    cout << "You landed on Community Chest!... There's only one Community Chest card for now... You get $20!" << endl;
    players[turn%players.size()].addCash(20);

}

void Game::init_to_empty(){
    auctionmoney = 0;
    tax = 0;
    counter = 0;
}

void Game::displaymoney(){
    for(int i = 0 ; i < players.size() ; i++){
        cout << "Player " << 1+i << " has $" << players[i].getCash() << " at his disposal" << endl; 
    }
}

void Game::jailcheck(){
    int n = turn%players.size();
    int check = board[players[n].getPosition()].getID();
    if(check == 5){
        jailtile();
    }
}

void Game::maketrade(){ 
    
    /* Haven't completed this function yet */

    char input;
    cout << "Which property would you like to trade? (Choose from 1 - " << players[turn%players.size()].getproperties() << ")" << endl;
    makeline();
    checkproperties();
    //cin << input;
    cout << "Traded to Player" << endl;

}

int Game::checkrailroads(){
    int check = 0;
    int x = 0;
    int n = turn%players.size();
    for(int i = 0; i < 4; i++){ 
        int owner = board[5+x].getOwner();
        if(owner == n+1){
            check++;
        }
        x+=10;
    }
    return check;
}

void Game::displayboard(){
    /* Have to make display function */
}

/* Assistor functions to the Game Class */

void makeline(){
    cout << "--------------------------------------------------------------------" << endl;
}