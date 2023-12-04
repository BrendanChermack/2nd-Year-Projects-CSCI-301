/*
Description of the problem to solve: Design the ADT for an online
shopping cart. The cart allows adding, removing, and editting the qunatity of items.
It also displaying of item prices and the total cost.
name: Brendan Chermack
startID: it1032ao
Due Date: 11:59 pm on September 21, Thursday.
Instructor: Professor Meichsner
*/
#include "ShoppingCart.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;
    /*** displays the current cart;
   * @param cart a dervided class of bag
   * @pre None
   * @post displays the contents of cart (for each item's: price, name and quantity)*/
void displayCart( ShoppingCart cart ) {
    cout << "-------------------------------------------------\n";
    cout << left << setw( 15 ) << "Name";
    cout << left << setw( 22 ) << "Unit_Price";
    cout << left << setw( 12 ) << "Quantity" << endl;
    vector<Item> cartContent = cart.toVector();
    for ( int i = 0; i < cartContent.size(); i++ ) {
        cout << left << setw( 15 ) << cartContent[ i ].getName();
        cout << left << setw( 22 ) << cartContent[ i ].getPrice();
        cout << left << setw( 12 ) << cartContent[ i ].getNumberOf() << "\n";
    }
    cout << "\nThe total charge is $" << cart.totalPrice();
    cout << "\n-------------------------------------------------\n";
}
int main() {
    char choice = 'y';//the users choice when deciding wheter or not they want to continue
    int choice1;//user choice for deciding if they want to add remove or change quantity
    ShoppingCart cart;//shoppingcart object is intialized
    Item itemTemp;//a temp item that will be overridden multiple times
    cout << "Welcome to XXX SHOPPING CENTER.\nEnter the item you selected as the following order :\nname unitPrice quantity\n( Name can not contain any space. Otherwise errors happen!) \n";
    while ( choice == 'y' ) {//user choice menu
        cout << "--> ";
        cin >> itemTemp;
        cart.add( itemTemp );//adds the users item 
        cout << "Want to continue y/n-->";//askes for continuation and will go on until y is not entered
        cin >> choice;
        cout << "\n";
    }
    cout << "Here is your order:\n";
    displayCart( cart );//displays the current cart

    cout << "\nWant to modify your order ? y / n-- >";//asks the user if modifacations are wanted to the cart
    cin >> choice;//users choice
    while ( choice == 'y' ) {//user choice menu
        cout << "\nWhat do you want ? \nEnter 1: add \n2: remove \n3: change quantity \n-->";
        cin >> choice1;//user cart manipluation choice
        if ( choice1 == 1 ) {//will add a users item to the cart
            cout << "Enter the item to add as the following order: \nname unitPrice quantity\n( Name can not contain any space.Otherwise errors happen!) \n--> ";
            cin >> itemTemp;
            cart.add( itemTemp );//adding method
            cout << "\nThe item has been added.\n";
        }
        else if ( choice1 == 2 ) {//will remove a users item to the cart
            cout << "Enter the item to remove as the following order: \nname unitPrice quantity\n( Name can not contain any space.Otherwise errors happen!) \n--> ";
            cin >> itemTemp;
            if ( cart.remove( itemTemp ) ) {//checks to see if the item is in the cart or not while trying to remove it
                cout << "\nThe item has been removed.\n";
            }
            else {
                cout << "\nNo such item in your shopping cart!\n";
            }
        }
        else if ( choice1 == 3 ) {//allows the user to change the quantity of an item in the car
            int change;
            vector<Item> cartItems = cart.toVector();//creates a vector of the array
            cout << "Enter the item to change as the following order: \nname unitPrice quantity\n( Name can not contain any space.Otherwise errors happen!) \n--> ";
            cin >> itemTemp;
            if ( cart.contains( itemTemp ) ) {//checks if the item is in the array
                cout << "Enter a new quantity-- >";
                cin >> change;
                while ( change <= 1 ) {//if an invalid number is entered it will loop until one is
                    cout << "enter a valid quanitiy" << endl;
                    cout << "Enter a new quantity-- >";
                    cin >> change;
                }
                for ( int i = 0; i < cartItems.size(); i++ ) {//loops through the vector
                    if ( cartItems[ i ] == itemTemp ) {//finds the item in the vector
                        cart.remove( itemTemp );//removes the item from the array
                        cartItems[ i ].setNumberOf( change );//changes the item in the vector
                        cart.add( cartItems[ i ] );//adds it back to the array
                    }
                }
            }
            else {
                cout << "Item is not in the cart.";
            }
        }
        else {// if 1 - 3 are not entered
            cout << "Enter a valid option";
        }
        cout << "\nWant to modify your order ? y / n-- >";//allows the user to make more adjustments
        cin >> choice;
    }
    cout << "\n\n Here is your updated order: \n";
    displayCart( cart );//displays the shopping cart
    cout << "\nThank you for shopping in XXX SHOPPING CENTER.";
}