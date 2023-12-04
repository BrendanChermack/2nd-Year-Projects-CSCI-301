/*
Description of the problem to solve: Design the ADT for an online
shopping cart. The cart allows adding, removing, and editting the qunatity of items.
It also displaying item prices and the total cost.
name: Brendan Chermack
startID: it1032ao
Due Date: 11:59 pm on September 21, Thursday.
Instructor: Professor Meichsner
*/
#ifndef ShoppingCartH
#define ShoppingCartH
#include "Item.h"
#include "Bag.h" // used for inheritance
class ShoppingCart: public Bag<Item> {
private:
    float total; // private varaible total
public:
    /*** Default constructor
    * @post  Initializes an empty shopping cart.*/
    ShoppingCart();
    /*** gets the total
    * @pre None
    * @post the total is returned*/
    float totalPrice() const;
    /*** adds an item to the array
    * @param newItem the item to be added
    * @pre array cannot be full
    * @post the item is added to the array and the total value of the quantity
    * and value are added to the total and true or false is returned */
    bool add( const Item& newItem );
    /*** removes an item from the array
    * @param newItem the item to be removed
    * @pre array cannot be empty
    * @post the item is removed from the array and the total value of the quantity
    * and value are subtracted to the total and true or false is returned */
    bool remove( const Item& newItem );
};
#include "ShoppingCart.cpp"//needed for centOS
#endif