#ifndef FrontListInterfaceH
#define FrontListInterfaceH

template<class ItemType>
class FrontListInterface {
public:
    /** Inserts an entry into front of a linked list
     @pre  None.
     @post  newEntry is in the front of the list.
     @param newEntry  The entry to insert into the sorted list. */
    virtual bool insertFront( const ItemType& newEntry ) = 0;
    /** Removes the front node.
     @pre  None.
     @post  If the removal of the first item if the list is not empty.
     @return  True if removal is successful, or false if not. */
    virtual bool removeFront() = 0;
    /** get the front item in the linked list
     @pre  None.
     @return  returns the front item. */
    virtual ItemType retrieveFront() const = 0;
    /*

    Orignates from List interface see that file for implmentations

    */
    /** Sees whether this list is empty. */
    virtual bool isEmpty() const = 0;

    /** Gets the current number of entries in this list. */
    virtual int getLength() const = 0;

    /** Removes the entry at a given position from this list. */
    virtual bool remove( int position ) = 0;

    /** Removes all entries from this list. */
    virtual void clear() = 0;

    /** Gets the entry at the given position in this list. */
    virtual ItemType getEntry( int position ) const = 0;
};
#endif