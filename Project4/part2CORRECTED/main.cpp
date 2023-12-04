/*
Description of the problem to solve: Spell checking problem: a program reads a word and checks if it is spelt correctly. It
compares a list of words against a dictionary which is a doubly linked list to see what is spelt correctly
name: Brendan Chermack
startID: it1032ao
Due Date: 11:50 pm on Oct 12, Thursday.
Instructor: Professor Meichsner
*/
#include "Node.h"
#include "DoublyLinkedBag.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream infile;//makes a infile object for ifstream
    infile.open( "dict.txt" );//opens a file
    string word;
    DoublyLinkedBag<string> dict;//diction of words
    if ( infile ) {//makes the dictions with a doubly linked list
        while ( infile >> word ) {
            dict.add( word );
        }
    }
    else {//error catching
        cout << "error file not found";
        return 0;
    }
    infile.close();//closes the file
    infile.open( "toBeSpellChecked.txt" );//opens the files that is compared against the dictionary
    cout << "The following words in the file “toBeSpellChecked.txt” are not spelled correctly :" << endl;
    while ( infile >> word ) {//prints out any miss spelt words
        if ( !dict.contains( word ) ) {
            cout << word << endl;
        }
    }
    cout << "Thanks for using the spell checker system.";
    infile.close();//closes the file
}