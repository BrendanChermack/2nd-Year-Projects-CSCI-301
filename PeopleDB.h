/*
Description of the problem to solve:  database containing person’s name and birthday. Is is
 able to enter, remove, modify, or search from the database. The names are unique.
The program is able to save the data in a file for use later.
name: Brendan Chermack
startID: it1032ao
Due Date: 11:50 pm on December 8, Friday
Instructor: Professor Meichsner
*/
#ifndef PeopleDBH
#define PeopleDBH

#include <string>
#include <fstream>
#include "People.h"
#include "BinarySearchTree.h"
class PeopleDB {
private:
    BinarySearchTree<People> db;
public:
    /**
 * Constructor for the PeopleDB class.
 *
 * @param dbFile The filename of the database file.
 * @pre None
 * @post A PeopleDB object is created and initialized with the provided database file.
 */
    PeopleDB( string dbFile );
    /**
 * Adds a new People object to the database.
 *
 * @param p The People object to add.
 * @return True if the addition is successful, False otherwise.
 */
    bool add( const People& p );
    /**
 * Removes a People object from the database.
 *
 * @param p The People object to remove.
 * @return True if the removal is successful, False otherwise.
 */
    bool remove( const People& p );
    /**
 * Modifies an existing People object in the database.
 *
 * @param p The People object with updated information.
 */
    void modify( People& p );
    /**
 * Searches for a People object in the database.
 *
 * @param p The People object to search for.
 * @return The People object 
 */
    People search( const People& p );
    /**
 * Displays the People objects in the database in preorder traversal.
 *
 * @param visit A function that is applied to each People object during traversal.
 */
    void displayPreorder( void visit( People& ) );
    /**
 * Displays the People objects in the database in sorted order.
 *
 * @param visit A function that is applied to each People object during traversal.
 */
    void displaySorted( void visit( People& ) );
};
#include "PeopleDB.cpp"
#endif