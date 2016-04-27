#include <iostream>
#include <string>
#include <vector>
#include "player.h"

Player::Player(std::string Name, int Number, int Cash, int Position){
    std::cout << "The object is created" << std::endl;
    name = Name;
    number = Number;
    cash = Cash;
    position = Position;
}

Player::~Player(){
    std::cout << "The object is being destroyed" << std::endl;
    init_to_empty();
}



std::string Player::player_getName(){
    return name;
}

int Player::player_getNumber(){
    return number;
}

int Player::player_getCash(){
    return cash;
}

int Player::player_getPosition(){
    return position;
}

void Player::player_editName(std::string Name){
    name = Name;
}

void Player::player_editNumber(int Number){
    number = Number;
}

void Player::player_editCash(int Cash){
    cash = Cash;
}
    
void Player::init_to_empty(){
    name = "blank";
    number = 0;
    cash = 1500;
    position = 0;
}

