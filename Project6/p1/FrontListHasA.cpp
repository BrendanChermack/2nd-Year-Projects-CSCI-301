#include "FrontListHasA.h"
#include "LinkedList.h"
#include <cassert>
template<class ItemType>
FrontListHasA<ItemType>::FrontListHasA() {//constructor
    listPtr = new LinkedList<ItemType>();
}
template<class ItemType>
FrontListHasA<ItemType>::FrontListHasA( const FrontListHasA<ItemType>& fList ) {//copy constructor
    listPtr = new LinkedList<ItemType>;
    for ( int position = 1; position <= fList.getLength(); position++ ) {
        listPtr->insert( position, fList.getEntry( position ) );
    }
}
template<class ItemType>
.FrontListHasA<ItemType>::~FrontListHasA() {//destructor
.    listPtr->clear();
}
template<class ItemType>
bool FrontListHasA<ItemType>::insert( const ItemType& newEntry ) {//inserts to the front of the list
    return listPtr->insert( 1, newEntry );
}
template<class ItemType>
bool FrontListHasA<ItemType>::remove() {//removes the front item
    return listPtr->remove( 1 );
}
template<class ItemType>
ItemType FrontListHasA<ItemType>::retrieve() const throw( PrecondViolatedExcep ) {
    //if ( !listPtr->isEmpty() ) {
    return listPtr->getEntry( 1 );
    // }
    // else {
    //     std::string message = "getEntry() called with an empty list or ";
    //     message = message + "invalid position.";
    //     throw( PrecondViolatedExcep( message ) );
    // }
}
template<class ItemType>
bool FrontListHasA<ItemType>::isEmpty() const {//returns if the list is empty
    return listPtr->isEmpty();
}
template<class ItemType>
int FrontListHasA<ItemType>::getLength() const {//gets the length of the list
    return listPtr->getLength();
}
template<class ItemType>
void FrontListHasA<ItemType>::clear() {//deletes all items in the list
    listPtr->clear();
}
template<class ItemType>
ItemType FrontListHasA<ItemType>::getEntry( int position ) const throw( PrecondViolatedExcep ) {//gets the entry used for copying the list
    return listPtr->getEntry( position );
}



