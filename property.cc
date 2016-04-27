#include <iostream>
#include <vector>
#include <string>
#include "property.h"
using namespace std;

Property::Property(){
    int rent = 0;
    int house = 0;
    string name = "Kevin's house";
    owner = 0;
}

Property::~Property(){
    int rent = 0;
    int house = 0;
    string name = "Kevin's house";
    owner = 0;
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

int Property::getPrice(){
    return price;
}

void Property::editOwner(int Owner){
    owner = Owner;
}

void Property::init(int ID, int Price, int Rent, string Name){
    name = Name;
    id = ID;
    price = Price;
    rent = Rent;
}

