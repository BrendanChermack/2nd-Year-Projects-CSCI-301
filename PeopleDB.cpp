/*
Description of the problem to solve:  database containing person’s name and birthday. Is is
 able to enter, remove, modify, or search from the database. The names are unique.
The program is able to save the data in a file for use later.
name: Brendan Chermack
startID: it1032ao
Due Date: 11:50 pm on December 8, Friday
Instructor: Professor Meichsner
*/
#include "PeopleDB.h"
#include "People.h"
#include "BinarySearchTree.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
PeopleDB::PeopleDB( string dbFile ) {
    ifstream infile;
    infile.open( dbFile.c_str() );

    People ppl;
    if ( !infile ) {
        cout << "File could not be found." << endl;
    }
    while (infile >> ppl ) {
        db.add( ppl );
    }
    infile.close();
}
bool PeopleDB::add( const People& p ) {
    return db.add( p );
}
bool PeopleDB::remove( const People& p ) {
    return db.remove( p );
}
void PeopleDB::modify( People& p ) {
    if ( db.remove( p ) ) {
        People newP;
        cout << "Found this person in the database.This person's data has been removed.\nEnter this person's new information: name and birthday (month day year): ";
        cin >> newP;
        db.add( newP );
    }
    else {
        cout << "Person not found." << endl;
    }
}
People PeopleDB::search( const People& p ) {
    return db.getEntry( p );
}
void PeopleDB::displayPreorder(void visit(People&))  {
    db.preorderTraverse( visit );
}
void PeopleDB::displaySorted( void visit( People& )) {
    db.inorderTraverse( visit );
}