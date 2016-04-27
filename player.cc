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



std::string Player::getName(){
    return name;
}

int Player::getNumber(){
    return number;
}

int Player::getCash(){
    return cash;
}

int Player::getPosition(){
    return position;
}

void Player::editName(std::string Name){
    name = Name;
}

void Player::editNumber(int Number){
    number = Number;
}

void Player::editCash(int Cash){
    cash = Cash;
}
    
void Player::init_to_empty(){
    name = "blank";
    number = 0;
    cash = 1500;
    position = 0;
}

