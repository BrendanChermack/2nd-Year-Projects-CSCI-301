#ifndef FrontListIsAH
#define FrontListIsAH
#include "FrontListInterface.h"
#include "LinkedList.h"
#include "Node.h"
#include "PrecondViolatedExcep.h"
template <class ItemType>
class FrontListIsA: public LinkedList<ItemType> {
public:
    FrontListIsA();
    FrontListIsA( const FrontListIsA<ItemType>& fList );
    virtual ~FrontListIsA();
    bool insertFront( const ItemType& newEntry );
    bool removeFront();
    ItemType retrieveFront() const;
    // The following methods have the same specifications
    // as given in ListInterface execpt insert remove and replace which are disabled:
    void clear()override;
    bool insert( int newPosition, const ItemType& newEntry )override;
    bool remove( int position )override;
    ItemType replace( int position, const ItemType& newEntry ) throw( PrecondViolatedExcep ) override;
};
#include "FrontListIsA.cpp"
#endif
