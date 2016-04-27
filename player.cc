#include <iostream>
#include <string>
#include <vector>
#include "player.h"

using namespace std;

Player::Player(){

}

Player::~Player(){
    std::cout << "The object is being destroyed" << std::endl;
    init_to_empty();
}



string Player::getName(){
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

void Player::addCash(int addedcash){
    cash += addedcash;
}

void Player::minusCash(int minuscash){
    cash -= minuscash;
}

void Player::editPosition(int Position){
    position += Position;
    if(position > 39){
       position = position % 40; 
       addCash(200);
    }
    
}
    
void Player::init_to_empty(){
    name = "blank";
    number = 0;
    cash = 1500;
    position = 0;
}

