#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Property{

public:
    
    /* Constructor and Deconstructor */
    Property();
    ~Property();

    /* Accessor functions */
    string getName();
    int getID();
    int getRent();
    int getHouse();
    int getOwner();
    int getPrice();
    
    void editOwner(int Owner);
    /* the initializing of properties */
    void init(int ID, int Price, int Rent, string Name);

private:
    string name;
    int id;
    int price;
    int rent;
    int house;
    int owner;
    bool monopoly;

};
