//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.
/*
Description of the problem to solve: Spell checking problem: a program reads a word and checks if it is spelt correctly. It
compares a list of words against a dictionary which is a doubly linked list to see what is spelt correctly
name: Brendan Chermack
startID: it1032ao
Due Date: 11:50 pm on Oct 12, Thursday.
Instructor: Professor Meichsner
*/
/** ADT bag: Link-based implementation.
	@file DoublyLinkedBag.cpp */

#include "DoublyLinkedBag.h"
#include "Node.h"
#include <cstddef>

template<class ItemType>
DoublyLinkedBag<ItemType>::DoublyLinkedBag(): headPtr( NULL ), itemCount( 0 ) {
}  // end default constructor

template<class ItemType>
DoublyLinkedBag<ItemType>::DoublyLinkedBag( const DoublyLinkedBag<ItemType>& aBag ) {
	itemCount = aBag.itemCount;
	Node<ItemType>* origChainPtr = aBag.headPtr;  // Points to nodes in original chain

	if ( origChainPtr == NULL )
		headPtr = NULL;  // Original bag is empty
	else {
		// Copy first node
		headPtr = new Node<ItemType>();
		headPtr->setItem( origChainPtr->getItem() );

		// Copy remaining nodes
		Node<ItemType>* newChainPtr = headPtr;      // Points to last node in new chain
		origChainPtr = origChainPtr->getNext();     // Advance original-chain pointer

		while ( origChainPtr != NULL ) {
			// Get next item from original chain
			ItemType nextItem = origChainPtr->getItem();

			// Create a new node containing the next item
			Node<ItemType>* newNodePtr = new Node<ItemType>( nextItem );

			// Link new node to end of new chain
			newChainPtr->setNext( newNodePtr );

			// Advance pointer to new last node
			newChainPtr = newChainPtr->getNext();

			// Advance original-chain pointer
			origChainPtr = origChainPtr->getNext();
		}  // end while

		newChainPtr->setNext( NULL );// Flag end of chain
	}  // end if
}  // end copy constructor

template<class ItemType>
DoublyLinkedBag<ItemType>::~DoublyLinkedBag() {
	clear();
}  // end destructor

template<class ItemType>
bool DoublyLinkedBag<ItemType>::isEmpty() const {
	return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int DoublyLinkedBag<ItemType>::getCurrentSize() const {
	return itemCount;
}  // end getCurrentSize

template<class ItemType>
bool DoublyLinkedBag<ItemType>::add( const ItemType& newEntry ) {
	// Add to beginning of chain: new node references rest of chain;
	// (headPtr is null if chain is empty)        
	Node<ItemType>* nextNodePtr = new Node<ItemType>();
	nextNodePtr->setItem( newEntry );
	nextNodePtr->setNext( headPtr );  // New node points to chain
	if ( headPtr != NULL ) {
		
	}
	
	//   Node<ItemType>* nextNodePtr = new Node<ItemType>(newEntry, headPtr); // alternate code

	headPtr = nextNodePtr;
	headPtr->setPrev( nextNodePtr );// New node is now first node
	itemCount++;

	return true;
}  // end add

template<class ItemType>
vector<ItemType> DoublyLinkedBag<ItemType>::toVector() const {
	vector<ItemType> bagContents;
	Node<ItemType>* curPtr = headPtr;
	int counter = 0;
	while ( ( curPtr != NULL ) && ( counter < itemCount ) ) {
		bagContents.push_back( curPtr->getItem() );
		curPtr = curPtr->getNext();
		counter++;
	}  // end while

	return bagContents;
}  // end toVector

template<class ItemType>
bool DoublyLinkedBag<ItemType>::remove( const ItemType& anEntry ) {
	Node<ItemType>* entryNodePtr = getPointerTo( anEntry );
	bool canRemoveItem = !isEmpty() && ( entryNodePtr != NULL );
	if ( canRemoveItem ) {
		// Copy data from first node to located node
		entryNodePtr->setItem( headPtr->getItem() );

		// Delete first node
		Node<ItemType>* nodeToDeletePtr = headPtr;
		headPtr = headPtr->getNext();
		// Return node to the system
		nodeToDeletePtr->setNext( NULL );
		delete nodeToDeletePtr;
		
			nodeToDeletePtr = NULL;
		

		headPtr->setPrev( NULL );
		itemCount--;
	} // end if
	return canRemoveItem;
}  // end remove

template<class ItemType>
void DoublyLinkedBag<ItemType>::clear() {
	Node<ItemType>* nodeToDeletePtr = headPtr;
	while ( headPtr != NULL ) {
		headPtr = headPtr->getNext();

		// Return node to the system
		nodeToDeletePtr->setNext( NULL );
		delete nodeToDeletePtr;

		nodeToDeletePtr = headPtr;
	}  // end while
	// headPtr is NULL; nodeToDeletePtr is NULL

	itemCount = 0;
}  // end clear

template<class ItemType>
int DoublyLinkedBag<ItemType>::getFrequencyOf( const ItemType& anEntry ) const {
	int frequency = 0;
	int counter = 0;
	Node<ItemType>* curPtr = headPtr;
	while ( ( curPtr != NULL ) && ( counter < itemCount ) ) {
		if ( anEntry == curPtr->getItem() ) {
			frequency++;
		} // end if

		counter++;
		curPtr = curPtr->getNext();
	} // end while

	return frequency;
}  // end getFrequencyOf

template<class ItemType>
bool DoublyLinkedBag<ItemType>::contains( const ItemType& anEntry ) const {
	return ( getPointerTo( anEntry ) != NULL );
}  // end contains

/* ALTERNATE 1
template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
   return getFrequencyOf(anEntry) > 0;
}
*/
/* ALTERNATE 2
template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
   bool found = false;
   Node<ItemType>* curPtr = headPtr;
   int i = 0;
   while (!found && (curPtr != NULL) && (i < itemCount))
   {
	  if (anEntry == curPtr-<getItem())
	  {
		 found = true;
	  }
	  else
	  {
		 i++;
		 curPtr = curPtr->getNext();
	  }  // end if
   }  // end while

   return found;
}  // end contains
*/

// private
// Returns either a pointer to the node containing a given entry 
// or the null pointer if the entry is not in the bag.
template<class ItemType>
Node<ItemType>* DoublyLinkedBag<ItemType>::getPointerTo( const ItemType& anEntry ) const {
	bool found = false;
	Node<ItemType>* curPtr = headPtr;

	while ( !found && ( curPtr != NULL ) ) {
		if ( anEntry == curPtr->getItem() )
			found = true;
		else
			curPtr = curPtr->getNext();
	} // end while

	return curPtr;
} // end getPointerTo


