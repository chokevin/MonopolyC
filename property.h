#include <iostream>
#include <vector>
#include <string>

class Property{

public:
    
    /* Constructor and Deconstructor */
    Property();
    ~Property();

    /* Accessor functions */
    int prop_getRent();
    int prop_getHouse();
    int prop_getHotel();
    std::string prop_getName();
    
    /* the initializing of properties */
    void init_property(std::string Name, int Rent, int House, int Hotel);
private:
    std::string name;
    int id;
    int rent;
    int house;
    int owner;


};
