/*
Description of the problem to solve: To create an Item class that can be used within the shoppingcart class.
Each item will have a name, price, and amount. Along with getter and setter functions for each. A == overloaded operator to compare 2 items.
Cout and Cin are to be overloaded as well.
name: Brendan Chermack
startID: it1032ao
Due Date: 11:59 pm on September 21, Thursday.
Instructor: Professor Meichsner
*/
#include "Item.h"
#include <iostream>
using namespace std;

Item::Item( string name, float price, int numberOf ) {
    this->name = name;
    this->price = price;
    this->numberOf = numberOf;
}//end of default constructor
void Item::setName( string name ) {
    this->name = name;
}//end of setName
void Item::setPrice( float price ) {
    this->price = price;
}//end of setPrice
void Item::setNumberOf( int numberOf ) {
    this->numberOf = numberOf;
}//end of setNameOf
bool operator==( const Item& i1, const Item& i2 ) {// == operator logic for item comparison
    if ( ( i1.getName() == i2.getName() )
        && ( i1.getPrice() == i2.getPrice() ) ) {
        return true;
    }//end if
    else {
        return false;
    }
}//end of operator==
istream& operator>>( istream& in, Item& i ) {
    in >> i.name >> i.price >> i.numberOf;
    return in;
}//end of operator>>
ostream& operator<<( ostream& out, Item& i ) {//formatting for item when displaye in the console
    out << "\nItem name: " << i.getName() << "\nItem price: " << i.getPrice() << "\nItem Quantity: " << i.getNumberOf();
    return out;
}//end of operator<<
