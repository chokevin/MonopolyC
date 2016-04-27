#include <iostream>
#include <vector>
#include <string>
#include "property.h"
using namespace std;

Property::Property(){
    int rent = 0;
    int house = 0;
    string name = "Kevin's house";
}

Property::~Property(){
    int rent = 0;
    int house = 0;
    string name = "Kevin's house";
}

string Property::getName(){
    return name;
}

int Property::getID(){
    return id;
}

int Property::getRent(){
    return rent;
}

int Property::getHouse(){
    return house;
}

int Property::getOwner(){
    return owner;
}

int Property::init(string Name, int ID, int Rent){
    name = Name;
    id = ID;
    rent = Rent;
    house = 0;
    owner = 0;
}

