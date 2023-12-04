/*
Description of the problem to solve: To create an Item class that can be used within the shoppingcart class.
Each item will have a name, price, and amount. Along with getter and setter functions for each. A == overloaded operator to compare 2 items.
Cout and Cin are to be overloaded as well.
name: Brendan Chermack
startID: it1032ao
Due Date: 11:59 pm on September 21, Thursday.
Instructor: Professor Meichsner
*/
#include <fstream>
#include <iostream>
#include "Item.h"
using namespace std;
int main() {
    //item delcarations
    Item i1( "candy", 10.00, 1 ), i2( "empty", 0, 0 ), i3( "mountain bike", 155.55, 6 );
    Item i4;
    
    cout << "Enter the name, price and quanity of the item: ";
    //reads a item from istream
    cin >> i4;
    //outputs in ostream
    cout << i1;
    cout << i4;
    cout << i3;
    //item comparison
    if ( i4 == i1 ) {
        cout << "\nitem 1 and item 4 are the same";
    }
    else {
        cout << "\nitem 1 and item 4 not the same";
    }
}