/*
Description of the problem to solve: Design the ADT for an online
shopping cart. The cart allows adding, removing, and editting the qunatity of items.
It also displaying item prices and the total cost.
name: Brendan Chermack
startID: it1032ao
Due Date: 11:59 pm on September 21, Thursday.
Instructor: Professor Meichsner
*/
#include <cstddef>
#include "ShoppingCart.h"
#include "Item.h"
#include <vector>//used to access array items
using namespace std;
ShoppingCart::ShoppingCart(): Bag<Item>(), total( 0.0 ) {
}// constructor implementation
float ShoppingCart::totalPrice() const{
    return total;
}//returns the total
bool ShoppingCart::add( const Item& newItem ) {
    total += ( newItem.getNumberOf() * newItem.getPrice() );
    return Bag<Item>::add( newItem );
}//calculates the new total and returns if the adding was successful
bool ShoppingCart::remove( const Item& newItem ) {
    if ( Bag<Item>::contains( newItem ) ) {//makes sure the bag has the item
        total -= ( newItem.getNumberOf() * newItem.getPrice() );
        return Bag<Item>::remove( newItem );
    }//end of it
    else {
        return false;
    }
}//calculates the new total and returns if the removing was successful