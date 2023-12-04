/*
Description of the problem to solve: To create an Item class that can be used within the shoppingcart class.
Each item will have a name, price, and amount. Along with getter and setter functions for each. A == overloaded operator to compare 2 items.
Cout and Cin are to be overloaded as well.
name: Brendan Chermack
startID: it1032ao
Due Date: 11:59 pm on September 21, Thursday.
Instructor: Professor Meichsner
*/
#include <string>//used for string varaibles
using namespace std;
#ifndef itemH
#define itemH
class Item {
private: //variables for name price and numberOf
    string name;
    float price;
    int numberOf;
public:
    /*** Constructor;
    * @param name the name of the item
    * @param price the price of the item
    * @param numberOf number of the item
    * @pre None
    * @post sets the name to an empty sting, price to 0 and numberOf to 0*/
    Item( string name = "", float price = 0.0, int numberOf = 0 );
    /*** gets the name
    * @pre None
    * @post the name is returned*/
    string getName() const{
        return name;
    }
    /*** Sets the name to a new value
    * @param name the name 
    * @pre None
    * @post the name this is called on setting it to a new value*/
    void setName( string name );
    /*** gets the price
    * @pre None
    * @post the price is returned*/
    float getPrice() const{
        return price;
    }
    /*** Sets the price to a new value
    * @param price the price
    * @pre None
    * @post the price this is called on setting it to a new value*/
    void setPrice( float price );
    /*** gets the numberOf
    * @pre None
    * @post the numberOf is returned*/
    int getNumberOf() const{
        return numberOf;
    }
    /*** Sets the numberOf to a new value
    * @param numberOf the numberOf
    * @pre None
    * @post the numberOf this is called on setting it to a new value*/
    void setNumberOf( int numberOf );
    /*** overloads the << operator
    * @param in the istream being used (cin)
    * @param i an item object
    * @pre None
    * @post allows the cin operator to be used to let the user assign values to an item*/
    friend istream& operator>>( istream& in, Item& i );
};
    /*** overloads the == operator
    * @param i1 an item object
    * @param i2 an item object
    * @pre None
    * @post allows them to be compared and the returns true or false*/
bool operator==( const Item& i1, const Item& i2 );
    /*** overloads the << operator
    * @param out the ostream being used (cout) 
    * @param i an item object
    * @pre None
    * @post allows an object to display in the console returns out*/
ostream& operator<<( ostream& out, Item& i );
#include "Item.cpp"
#endif