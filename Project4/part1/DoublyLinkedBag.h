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
	@file DoublyLinkedBag.h
	Listing 4-3 */
#ifndef DoublyLinkedBagH
#define DoublyLinkedBagH

#include "BagInterface.h"
#include "Node.h"

template<class ItemType>
class DoublyLinkedBag: public BagInterface<ItemType> {
private:
	Node<ItemType>* headPtr; // Pointer to first node
	int itemCount;           // Current count of bag items

	// Returns either a pointer to the node containing a given entry
	// or the null pointer if the entry is not in the bag.
	Node<ItemType>* getPointerTo( const ItemType& target ) const;

public:
	DoublyLinkedBag();
	DoublyLinkedBag( const DoublyLinkedBag<ItemType>& aBag ); // Copy constructor
	virtual ~DoublyLinkedBag();                       // Destructor should be virtual
	int getCurrentSize() const;
	bool isEmpty() const;
	bool add( const ItemType& newEntry );
	bool remove( const ItemType& anEntry );
	void clear();
	bool contains( const ItemType& anEntry ) const;
	int getFrequencyOf( const ItemType& anEntry ) const;
	vector<ItemType> toVector() const;
}; // end LinkedBag

#include "DoublyLinkedBag.cpp"
#endif