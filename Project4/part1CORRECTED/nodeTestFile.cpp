/*
Description of the problem to solve: Spell checking problem: a program reads a word and checks if it is spelt correctly. It
compares a list of words against a dictionary which is a doubly linked list to see what is spelt correctly
name: Brendan Chermack
startID: it1032ao
Due Date: 11:50 pm on Oct 12, Thursday.
Instructor: Professor Meichsner
*/
#include "Node.h"
#include <iostream>
#include <cassert>

int main() {
    // Create nodes
    Node<int> node1( 5 );
    Node<int> node2( 10 );
    Node<int> node3( 15 );

    // Test setting and getting items
    assert( node1.getItem() == 5 );
    assert( node2.getItem() == 10 );

    node1.setItem( 6 );
    assert( node1.getItem() == 6 );

    // Test setting and getting next and previous pointers
    node1.setNext( &node2 );
    node2.setPrev( &node1 );
    node2.setNext( &node3 );
    node3.setPrev( &node2 );

    assert( node1.getNext() == &node2 );
    assert( node2.getPrev() == &node1 );
    assert( node2.getNext() == &node3 );
    assert( node3.getPrev() == &node2 );

    // Test the constructors
    Node<int> node4( 20, &node3 );
    Node<int> node5( 25, nullptr, &node4 );

    assert( node4.getItem() == 20 );
    assert( node4.getNext() == &node3 );
    assert( node5.getItem() == 25 );
    assert( node5.getPrev() == &node4 );

    std::cout << "All tests passed!" << std::endl;

    return 0;
}
