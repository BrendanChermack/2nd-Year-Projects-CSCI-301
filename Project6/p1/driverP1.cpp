#include <iostream>
#include <string>
#include "FrontListHasA.h"
#include "LinkedList.h"
using namespace std;

void displayList( FrontListInterface<string>* listPtr ) {
    cout << "The front list contains " << endl;
   for ( int pos = 1; pos <= listPtr->getLength(); pos++ ) {
        cout << listPtr->getEntry(pos) << " ";
   } // end for
    cout << endl << endl;
}  // end displayList
void copyConstrTest() {
    FrontListHasA<string> list;
    string items[] = { "zero", "one", "two", "three", "four", "five" };
    for ( int i = 0; i < 6; i++ ) {
        cout << "Adding " << items[ i ] << endl;
        list.insert( items[ i ] );
    }
    displayList( &list );

    FrontListHasA<string> copiedlist(list);
    cout << "Copy of list: ";
    displayList( &copiedlist );

    cout << "The copied list: ";
    displayList( &list );
}
void FrontListTester( FrontListInterface<string>* listPtr ) {
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
    //insert names into lsit
    listPtr->insert( tom );
    listPtr->insert( sue );
    listPtr->insert( jerry );

    // display the list
    cout << "List should contain\nBrent, Donna, " <<
        "Jerry, Luke, Sue, Tom" << endl;
    cout << "\nList actually contains:" << endl;
    displayList( listPtr );
    cout << endl;

    // test retrieve
    cout << "\nTest retrieve:\n" << endl;

    // The first name of the front list is
    cout << "first name of the front list is " << listPtr->retrieve(  ) << endl;
    

    // test getLength and getEntry
   std::cout << "\nTest getLength and getEntry:\n" << endl;

    cout << "\nList has " << listPtr->getLength() << " entries, as follows:\n" << endl;
    for ( int i = 1; i <= listPtr->getLength(); i++ )
        cout << i << ": " << listPtr->getEntry( i ) << endl;


    // test remove
    cout << "\nTest remove:\n" << endl;

    // remove first entry
    cout << "\nRemoving front item (Jerry): " << listPtr->remove(  ) << "; should be 1 (true)" << endl;
    cout << "\nAfter removing Jerry, list contains " << listPtr->getLength()
        << " items, as follows:" << endl;
    displayList( listPtr );

    // remove new first
    cout << "\nRemoving next front item (Sue): " << listPtr->remove( ) << "; should be 1 (true)" << endl;
    cout << "\nAfter removing Sue, list contains " << listPtr->getLength()
        << " items, as follows:" << endl;
    displayList( listPtr );

    // remove new first
    cout << &"\nRemoving next front item (Tom): "[ listPtr->remove(  ) ] << "; should be 1 (true)" << endl;
    cout << "\nAfter removing last item, list contains " << listPtr->getLength()
        << " items, as follows:" << endl;
    displayList( listPtr );
//remove empty list
    cout << "\nRemoving empty list: " << listPtr->remove(  ) << "; should be 0 (false)" << endl;
    cout << "\n " << listPtr->remove(  ) << "; should be 0 (false)" << endl;

//empty list display
    cout << "\nThe list contains " << listPtr->getLength()
        << " items, as follows:" << endl;
    displayList( listPtr );

    // test clear()
    cout << "\nAdding items Tom and Jerry and Test clear():\n" << endl;
    listPtr->insert( tom );
    listPtr->insert( jerry );
    listPtr->clear();
//empty test again
    if ( listPtr->isEmpty() )
        cout << "\nThe list is empty after invoking clear()." << endl;
    else
        cout << "\nclear() error" << endl;
} // end sortedListTester

void listOpsTester( FrontListInterface<string>* listPtr ) {
    string luke = "Luke";
    string brent = "Brent";
    string donna = "Donna";

    listPtr->insert( luke );
    listPtr->insert( brent );
    listPtr->insert( donna );

    displayList( listPtr );

    cout << "isEmpty: returns " << listPtr->isEmpty() << "; should be 0 (false)" << endl;
    cout << "getLength returns : " << listPtr->getLength() << "; should be 3" << endl;

    cout << "remove(): returns " << listPtr->remove(  ) << "; should be 1 (true)" << endl;
    cout << "remove(): returns " << listPtr->remove(  ) << "; should be 1 (true)" << endl;
    cout << "remove(): returns " << listPtr->remove() << "; should be 1 (true)" << endl;
    cout << "remove(): returns " << listPtr->remove() << "; should be 0 (false)" << endl;

    displayList( listPtr );
    cout << "getLength returns : " << listPtr->getLength() << "; should be 0" << endl;
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
    copyConstrTest();
    FrontListInterface<string>* listPtr = new FrontListHasA<string>();
    cout << "Testing the Link-Based Front List:" << endl;
    FrontListTester( listPtr );
    cout << "======================================" << endl;

    cout << "\nTesting the List Operations:" << endl;
    listOpsTester( listPtr );

    return 0;
}