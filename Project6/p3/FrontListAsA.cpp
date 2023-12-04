#include "FrontListAsA.h"
#include <cassert>

template <class ItemType>
FrontListAsA<ItemType>::FrontListAsA() { }//constructor
template <class ItemType>
FrontListAsA<ItemType>::FrontListAsA( const FrontListAsA<ItemType>& fList ):LinkedList<ItemType>( fList ) { }//copy constructor
template <class ItemType>
FrontListAsA<ItemType>::~FrontListAsA() {//destructor
    clear();
}
template <class ItemType>
bool FrontListAsA<ItemType>::insertFront( const ItemType& newEntry ) {//inserts to the front of the list
    return this->insert( 1, newEntry );
}
template <class ItemType>
bool FrontListAsA<ItemType>::removeFront() {//removes the front item
    if ( !LinkedList<ItemType>::isEmpty() ) {//makes sure list is not empty
        return remove( 1 );
    }
    return false;
}
template <class ItemType>
ItemType FrontListAsA<ItemType>::retrieveFront() const {//gets the front item
    return getEntry( 1 );
}
template <class ItemType>
bool FrontListAsA<ItemType>::isEmpty() const{//checks if the list is empty
    return LinkedList<ItemType>::isEmpty();
}
template <class ItemType>
int FrontListAsA<ItemType>::getLength() const{//gets the lenght of the list
    return LinkedList<ItemType>::getLength();
}
template <class ItemType>
bool FrontListAsA<ItemType>::remove( int position ) {//remove function from linked list
    return LinkedList<ItemType>::remove( position );
}
template <class ItemType>
void FrontListAsA<ItemType>::clear() {//clears the list
    return LinkedList<ItemType>::clear();
}
template<class ItemType>
ItemType FrontListAsA<ItemType>::getEntry( int position ) const throw( PrecondViolatedExcep ) {//gets the entry of the linked list
    return LinkedList<ItemType>::getEntry( position );
}