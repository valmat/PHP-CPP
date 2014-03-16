/**
 *  valueiterator.h
 *
 *  ValueIterator - allows the iteration variable of class Value.
 *  It designed for natural iteration objects, arrays and other iterable types. And have minimal overhead.
 *
 *  @copyright 2013 Copernica BV
 */


/**
 *  Set up namespace
 */
namespace Php {


class ValueIterator
{
public:

    /**
     *  Constructor ValueIterator
     *  @param  arr HashTable
     */
    ValueIterator(HashItem *phi): phItem(phi)
    {
        phi->reset();
    }
    
    /**
     *  Constructor for empty ValueIterator.
     *  Used to finish the iterations
     */
    ValueIterator(std::nullptr_t n) : phItem(nullptr) {}

    /**
     *  Copy Constructor
     */
    ValueIterator(const ValueIterator& that) = delete;

    /**
     *  Move constructor
     */
    ValueIterator(ValueIterator&& that)
    {
        phItem = that.phItem;
        // clear the other object
        that.phItem = nullptr;
    }

    /**
     *  Move assignment
     */
    Value &operator=(ValueIterator&& that)
    {
        phItem = that.phItem;
        // clear the other object
        that.phItem = nullptr;
    }

    /**
     *  Increment prefix operator
     */
    ValueIterator& operator++()
    {
        next();
        return *this;
    }

    /**
     *  Increment postfix operator
     */
    ValueIterator& operator++(int)
    {
        return operator++();
    }

    /**
     *  Add a int-value to the ValueIterator-object
     */
    ValueIterator& operator+=(unsigned int n)
    {
        for(unsigned int i=0; i < n; ++i) next();
        return *this;
    }

    bool operator==(const ValueIterator& rhs) const
    {
        // If one of items is empty
        // The order of the following tests is optimized. Do not change it.
        if(!isEmpty() &&  rhs.isEmpty() ) return false;
        if( isEmpty() &&  rhs.isEmpty() ) return true;
        if( isEmpty() && !rhs.isEmpty() ) return false;

        // If both are not empty
        return phItem->compare(rhs.phItem);
    }

    bool operator!=(const ValueIterator& rhs) const
    {
        return !operator==(rhs);
    }

    HashItem& operator*()
    {
        return *phItem;
    }
    
    HashItem* operator->()
    {
        return phItem;
    }

    /**
     *  Destructor
     */
    ~ValueIterator()
    {
        // delete HashItem pointer
        if(phItem) delete phItem;
    }


private:

    /**
     *  Check the current item is empty
     */
    bool isEmpty() const
    {
        // True, if phItem == nullptr or  phItem is empty.
        return (!phItem || phItem->isEmpty());
    }

    /**
     *  next iteration
     */
    bool next()
    {
        // Only if phItem != nullptr
        if(phItem) phItem->next();
    }

    // Position in the internal hash table. Pointer to HashItem
    HashItem *phItem;
};

/**
 *  End of namespace
 */
}
