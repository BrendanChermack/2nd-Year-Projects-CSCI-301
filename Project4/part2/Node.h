//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.
/*
Description of the problem to solve: Spell checking problem: a program reads a word and checks if it is spelt correctly. It
compares a list of words against a dictionary which is a doubly linked list to see what is spelt correctly
name: Brendan Chermack
startID: it1032ao
Due Date: 11:50 pm on Oct 12, Thursday.
Instructor: Professor Meichsner
*/
/** @file Node.h
    Listing 4-1 */
#ifndef NODE_
#define NODE_

template<class ItemType>
class Node {
private:
   ItemType        item; // A data item
   Node<ItemType>* next; // Pointer to next node
   Node<ItemType>* prev; // Pointer to prev node

public:
   Node();
   Node( const ItemType& anItem );
   Node( const ItemType& anItem, Node<ItemType>* nextNodePtr );
   Node( const ItemType& anItem, Node<ItemType>* nextNodePtr, Node<ItemType>* prevNodePtr );//doubly style node
   void setItem( const ItemType& anItem );
   void setNext( Node<ItemType>* nextNodePtr );
   void setPrev( Node<ItemType>* prevNodePtr );//sets the prev node
   ItemType getItem() const;
   Node<ItemType>* getNext() const;
   Node<ItemType>* getPrev() const;//gets the prev node
}; // end Node

#include "Node.cpp"
#endif