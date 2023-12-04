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
};
#endif