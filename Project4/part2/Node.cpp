/*
Description of the problem to solve: Spell checking problem: a program reads a word and checks if it is spelt correctly. It
compares a list of words against a dictionary which is a doubly linked list to see what is spelt correctly
name: Brendan Chermack
startID: it1032ao
Due Date: 11:50 pm on Oct 12, Thursday.
Instructor: Professor Meichsner
*/
#include "Node.h"
#include <cstddef>

template<class ItemType>
Node<ItemType>::Node(): next( NULL ), prev( NULL ) {
} // end default constructor

template<class ItemType>
Node<ItemType>::Node( const ItemType& anItem ) : item( anItem ), next( NULL ), prev( NULL ) {
} // end constructor

template<class ItemType>
Node<ItemType>::Node( const ItemType& anItem, Node<ItemType>* nextNodePtr ) :
   item( anItem ), next( nextNodePtr ), prev( NULL ) {
} // end constructor
template<class ItemType>
Node<ItemType>::Node( const ItemType& anItem, Node<ItemType>* nextNodePtr, Node<ItemType>* prevNodePtr ) :
   item( anItem ), next( nextNodePtr ), prev( prevNodePtr ) {
} // end constructor
template<class ItemType>
void Node<ItemType>::setItem( const ItemType& anItem ) {
   item = anItem;
} // end setItem

template<class ItemType>
void Node<ItemType>::setNext( Node<ItemType>* nextNodePtr ) {
   next = nextNodePtr;
} // end setNext

template<class ItemType>
void Node<ItemType>::setPrev( Node<ItemType>* prevNodePtr ) {
   prev = prevNodePtr;
}// end setPrev

template<class ItemType>
ItemType Node<ItemType>::getItem() const {
   return item;
} // end getItem

template<class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const {
   return next;
} // end getNext

template<class ItemType>
Node<ItemType>* Node<ItemType>::getPrev() const {
   return prev;
   // end getPrev
}
