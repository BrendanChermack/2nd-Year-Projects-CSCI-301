#ifndef FrontListH
#define FrontListH

#include "FrontListInterface.h"
#include "ListInterface.h"
#include "Node.h"
#include "PrecondViolatedExcep.h"
#include <cassert>
template <class ItemType>
class FrontListHasA: public FrontListInterface<ItemType> {
private:
    ListInterface<ItemType>* listPtr;
public:
    FrontListHasA();
    FrontListHasA( const FrontListHasA<ItemType>& fList );
    ~FrontListHasA();

    bool insert( const ItemType& newEntry );
    bool remove();
    ItemType retrieve() const throw( PrecondViolatedExcep );
    // The following methods have the same specifications
    // as given in ListInterface:
    bool isEmpty() const;
    int getLength() const ;
    void clear();
    ItemType getEntry( int position ) const throw( PrecondViolatedExcep );
};
#include "FrontListHasA.cpp"
#endif
