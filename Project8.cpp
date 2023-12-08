/*
Description of the problem to solve:  database containing person’s name and birthday. Is is
 able to enter, remove, modify, or search from the database. The names are unique.
The program is able to save the data in a file for use later.
name: Brendan Chermack
startID: it1032ao
Due Date: 11:50 pm on December 8, Friday
Instructor: Professor Meichsner
*/
#include <fstream>
#include <string>
#include <iostream>
#include "PeopleDB.h"
using namespace std;
ofstream fsOut( "updated_db.txt", ios_base::app );
/**
 * Displays the details of a People object to the screen.
 *
 * @param p The People object to be displayed.
 */
void toScreen( People& p ) {
    cout << p << endl;
}
/**
*Writes the details of a People object to a file.
*
* @param p The People object to be written to the file.
* @pre fsOut should be an open file stream.
* @post The details of p are appended to the file.
*/
void toFile( People& p ) {
    fsOut << p << endl;//output to a file
}
/**
 * Displays a menu for interacting with the People database.
 *
 * @pre None
 * @post The menu options are displayed to the screen.
 */
void menu() {
    cout << "Please enter your option" << endl;
    cout << "1. Add a person" << endl;
    cout << "2. Remove a person" << endl;
    cout << "3. Modify the database" << endl;
    cout << "4. Search for a person in the database" << endl;
    cout << "5. Display the database" << endl;
    cout << "6. Display the database in sorted order" << endl;
    cout << "7. Save and Exit" << endl;
}
int main() {
    string dbName;
    // Prompt user for the database file name
    cout << "Welcome to xxx database system. Please enter the file that initial people list : \n";
    cin >> dbName;
    // Create a PeopleDB object using the provided file name
    PeopleDB db( dbName );
    // Display initial contents of the database
    db.displayPreorder( toScreen );
    cout << endl;
    // Display the menu options to the user
    menu();
    // Variable to store the user's menu choice
    int option;
    cin >> option;
    // Main loop to process user's menu choices
    while ( option != 7 ) {
        if ( option == 1 ) {
            // Option to add a new person to the database
            People p;
            cout << "To add, enter the person's name and birthday (month day year): ";
            char c = 'y';
            while ( c == 'y' ) {
                cin >> p;
                db.add( p );
                cout << "Do you want to add another person? (y/n): ";
                cin >> c;
            }
        }
        else if ( option == 2 ) {
            // Option to remove a person from the database
            People p;
            cout << "To remove, enter the person's name and birthday (month day year): ";
            char c = 'y';
            while ( c == 'y' ) {
                cin >> p;
                if ( !db.remove( p ) ) {
                    cout << "Person not found. \n";
                }
                else {
                    cout << "Person removed from the database. \n";
                }

                cout << "Do you want to remove another person? (y/n): ";
                cin >> c;
            }
        }
        else if ( option == 3 ) {
            // Option to modify a person's details in the database
            People p;
            cout << "To modify, enter the person's name and birthday (month day year): ";
            char c = 'y';
            while ( c == 'y' ) {
                cin >> p;
                db.modify( p );
                cout << "Do you want to modify another person? (y/n): ";
                cin >> c;
            }
        }
        else if ( option == 4 ) {
            // Option to search for a person in the database
            People p;
            cout << "To search, enter the person's name and birthday (month day year): ";
            char c = 'y';
            while ( c == 'y' ) {
                cin >> p;
                if ( db.search( p ) == p ) {
                    cout << "Found this person in the database: " << endl;
                    cout << p << endl;
                }
                else {
                    cout << "Person not found. \n";
                }
                cout << "Do you want to search again? (y/n): ";
                cin >> c;
            }
        }
        else if ( option == 5 ) {
            // Display the database in preorder
            db.displayPreorder( toScreen );
            cout << endl;
        }
        else if ( option == 6 ) {
            // Display the database in sorted order
            db.displaySorted( toScreen );
            cout << endl;
        }
        else {
            // Handle invalid menu option
            cout << "Invalid option. \n" << endl;
        }
        // Show the menu again for further actions
        menu();
        cin >> option;
    }
    // Save the final state of the database to a file
    db.displayPreorder( toFile );
    cout << " The updated database has been saved to " << "updated_db.txt" << " Bye!";
}