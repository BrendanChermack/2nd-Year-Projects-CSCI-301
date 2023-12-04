#ifndef FrontListAsAH
#define FrontListAsAH
#include "LinkedList.h"
#include "FrontListInterface.h"
#include "Node.h"
#include "PrecondViolatedExcep.h"
template <class ItemType>
class FrontListAsA: public FrontListInterface<ItemType>, private LinkedList<ItemType> {
public:
    FrontListAsA();
    FrontListAsA( const FrontListAsA<ItemType>& fList );
    virtual ~FrontListAsA();

    bool insertFront( const ItemType& newEntry );
    bool removeFront();
    ItemType retrieveFront() const;
    // The following methods are inherited and have the same 
       // specifications as given in ListInterface:
    bool isEmpty()const;
    int getLength()const;
    bool remove( int position );
    void clear();
    ItemType getEntry( int position )const throw( PrecondViolatedExcep );

};

#include "FrontListAsA.cpp"
#endif