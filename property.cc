#include <iostream>
#include <vector>
#include <string>
#include "property.h"

Property::Property(){
    int rent = 0;
    int house = 0;
    int hotel = 0;
    std::string name = "Kevin's house";
}

Property::~Property(){
    int rent = 0;
    int house = 0;
    int hotel = 0;
    std::string name = "Kevin's house";
}

int Property::prop_getRent(){
    return rent;
}

int Property::prop_getHouse(){
    return house;
}

int Property::prop_getHotel(){
    return hotel;
}

std::string Property::prop_getName(){
    return name;
}



