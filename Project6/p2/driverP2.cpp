#include "FrontListIsA.h"
#include <iostream>
#include <string>
using namespace std;
void displayList( FrontListIsA<string>* listPtr ) {
    cout << "The front list contains " << endl;
    for ( int pos = 1; pos <= listPtr->getLength(); pos++ ) {
        cout << listPtr->getEntry( pos ) << " ";
    }
    cout << endl << endl;
}
void copyConstructorTester() {
    FrontListIsA<string> list;
    string items[] = { "zero", "one", "two", "three", "four", "five" };
    for ( int i = 0; i < 6; i++ ) {
        cout << "Adding " << items[ i ] << endl;
        list.insertFront( items[ i ] );
    }
    displayList( &list );

    FrontListIsA<string> copyOfList( list );
    cout << "Copy of list: ";
    displayList( &copyOfList );

    cout << "The copied list: ";
    displayList( &list );
}  // end copyConstructorTester

void frontListIsATester( FrontListIsA <string>* listPtr ) {
    string luke = "Luke";
    string brent = "Brent";
    string donna = "Donna";
    string tom = "Tom";
    string sue = "Sue";
    string jerry = "Jerry";
    //empty test
    cout << "\nTest isEmpty with an empty list:" << endl;
    if ( listPtr->isEmpty() )
        cout << "OK" << endl;
    else
        cout << "isEmpty() error" << endl;

    //removal on empty list test
    //empty list removal
    cout << "\nTrying to remove on an empty list: " << listPtr->removeFront() << "; should be 0 (false)" << endl;
    cout << "\nAfter trying to remove an item " << listPtr->getLength()
        << " list is, as follows:" << endl;
    displayList( listPtr );
    //insert names into lsit
    listPtr->insertFront( tom );
    listPtr->insertFront( sue );
    listPtr->insertFront( jerry );

    // display the list
    cout << "List should contain\nJerry, Sue, Tom" << endl;
    cout << "\nList actually contains:" << endl;
    displayList( listPtr );
    cout << endl;

    // test retrieve
    cout << "\nTest front retrieve:\n" << endl;
    cout << "Front item should be Jerry: " << listPtr->retrieveFront() << endl;

    // test getLength and getEntry
    cout << "\nTest getLength and getEntry:\n" << endl;

    cout << "\nList has " << listPtr->getLength() << " entries, as follows:\n" << endl;
    for ( int i = 1; i <= listPtr->getLength(); i++ )
        cout << i << ": " << listPtr->getEntry( i ) << endl;


    // test remove
    cout << "\nTest remove:\n" << endl;

    // remove first entry
    cout << "\nRemoving front item (jerry): " << listPtr->removeFront( ) << "; should be 1 (true)" << endl;
    cout << "\nAfter removing front item, list contains " << listPtr->getLength()
        << " items, as follows:" << endl;
    displayList( listPtr );

    // remove next
    cout << "\nRemoving new front item: " << listPtr->removeFront( ) << "; should be 1 (true)" << endl;
    cout << "\nAfter removing Sue, list contains " << listPtr->getLength()
        << " items, as follows:" << endl;
    displayList( listPtr );

    // test clear()
    cout << "\nTest clear():\n" << endl;
    listPtr->clear();

    if ( listPtr->isEmpty() )
        cout << "\nThe list is empty after invoking clear()." << endl;
    else
        cout << "\nclear() error" << endl;
} // end sortedListTester

void listOpsTester( FrontListIsA <string>* listPtr ) {
    string luke = "Luke";
    string brent = "Brent";
    string donna = "Donna";
    string tom = "Tom";
    string sue = "Sue";
    string jerry = "Jerry";

    listPtr->insertFront( luke );
    listPtr->insertFront( brent );
    listPtr->insertFront( donna );
    listPtr->insertFront( tom );
    listPtr->insertFront( sue );
    listPtr->insertFront( jerry );

    displayList( listPtr );

    cout << "isEmpty: returns " << listPtr->isEmpty() << "; should be 0 (false)" << endl;
    cout << "getLength returns : " << listPtr->getLength() << "; should be 6" << endl;

    cout << "remove(): returns " << listPtr->removeFront( ) << "; should be 1 (true)" << endl;
    cout << "remove(): returns " << listPtr->removeFront() << "; should be 1 (true)" << endl;
    
    cout << "remove(6) (LinkedLists disabled remove): returns " << listPtr->remove( 6 ) << "; should be 0 (false)" << endl;
    displayList( listPtr );
    cout << "getLength returns : " << listPtr->getLength() << "; should be 4" << endl;
    cout << "clear: " << endl;
    listPtr->clear();
    cout << "isEmpty: returns " << listPtr->isEmpty() << "; should be 1 (true)" << endl;

    try {
        cout << "Attempt an illegal retrieval from position 6: " << endl;
        listPtr->getEntry( 6 );
    }
    catch ( PrecondViolatedExcep e ) {
        cout << e.what() << endl;
    }  // end try/catch
} // end listOpsTester

int main() {
    copyConstructorTester();

    FrontListIsA <string>* listPtr = new FrontListIsA<string>();
    cout << "Testing the Link-Based Front List:" << endl;
    frontListIsATester( listPtr );
    cout << "======================================" << endl;

    cout << "\nTesting the List Operations:" << endl;
    listOpsTester( listPtr );

    return 0;
}  // end main
