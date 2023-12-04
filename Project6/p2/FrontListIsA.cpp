#include "FrontListIsA.h"
#include <cassert>
template<class ItemType>
FrontListIsA<ItemType>::FrontListIsA() { }//constructor
template<class ItemType>
FrontListIsA<ItemType>::FrontListIsA( const FrontListIsA<ItemType>& fList ): LinkedList<ItemType>( fList ) { }//copy constructor
template<class ItemType>
FrontListIsA<ItemType>::~FrontListIsA() { }//destructor
template<class ItemType>
bool FrontListIsA<ItemType>::insertFront( const ItemType& newEntry ) {//inserts to the front of the list
    return LinkedList<ItemType>::insert( 1, newEntry );
}
template<class ItemType>
bool FrontListIsA<ItemType>::removeFront() {//removes the front item
    if ( !LinkedList<ItemType>::isEmpty() ) {
        return LinkedList<ItemType>::remove( 1 );
    }
    return false;
}
template<class ItemType>
void FrontListIsA<ItemType>::clear() {//deletes all items
    while ( !LinkedList<ItemType>::isEmpty() )
        removeFront( );
}
template<class ItemType>
ItemType FrontListIsA<ItemType>::retrieveFront() const {//gets the front item
    return LinkedList<ItemType>::getEntry( 1 );
}
template<class ItemType>
bool FrontListIsA<ItemType>::insert( int newPosition, const ItemType& newEntry ) {//disabled insert from linked list
    return false;
}
template<class ItemType>
bool FrontListIsA<ItemType>::remove( int newPosition ) {////disabled remove from linked list
    return false;
}
template<class ItemType>
ItemType FrontListIsA<ItemType>::replace( int position, const ItemType& newEntry ) throw( PrecondViolatedExcep ) {//disabled function
    throw PrecondViolatedExcep( "Illegal call." );
}