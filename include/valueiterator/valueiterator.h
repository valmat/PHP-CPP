/**
 *  valueiterator.h
 *
 *  ValueIterator - allows the iteration variable of type Value.
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
     *  Constructor for empty ValueIterator.
     *  Used to finish the iterations
     */
    ValueIterator(std::nullptr_t n) : phItem(nullptr) {
        std::cout << "\x1b[1;32m\n ValueIterator(std::nullptr_t n) \n\x1b[0;0m";
    }
    ~ValueIterator() {
        std::cout << "\x1b[1;33m\n ~ValueIterator(" << phItem << ") \n\x1b[0;0m";

        // delete HashItem pointer
        if(phItem) delete phItem;

    }

    /**
     *  Copy Constructor
     */
    ValueIterator(const ValueIterator& that) = delete;
    /*
    ValueIterator(const ValueIterator& that) : phItem(that.phItem)
    {
        std::cout << "\x1b[1;34m\n Copy Constructor \n\x1b[0;0m";
    }
    */

    /**
     *  Move Constructor
     */
    /*
    ValueIterator(ValueIterator&& that) : phItem(std::move(that.phItem))
    {
        std::cout << "\x1b[1;34m\n Move Constructor \n\x1b[0;0m";
    }
    */
    /**
     *  Move constructor
     */
    ValueIterator(ValueIterator&& that)
    {
        std::cout << "\x1b[1;34m\n Move Constructor \n\x1b[0;0m";
        phItem = that.phItem;
        // clear the other object
        that.phItem = nullptr;
    }


    /**
     *  Constructor ValueIterator
     *  @param  arr HashTable
     */
    ValueIterator(HashItem *phi): phItem(phi)
    {
        std::cout << "\x1b[1;32m\n ValueIterator(HashItem *phi) \n\x1b[0;0m";
        phi->reset();
    }

    /**
     *  Increment prefix operator
     */
    ValueIterator& operator++() {
        std::cout << "\x1b[0;31m\n ValueIterator& operator++() \n\x1b[0m";
        phItem->next();
        return *this;
    }

    /**
     *  Increment postfix operator
     */
    /*
    ValueIterator operator++(int) {
        ValueIterator tmp(*this);
        operator++();
        return tmp;
    }
    */
    ValueIterator& operator++(int) {
        std::cout << "\x1b[0;31m\n ValueIterator& operator++(int) \n\x1b[0m";
        return operator++();
        //ValueIterator tmp(*this);
        //operator++();
        //return tmp;
    }

    ValueIterator& operator+=(unsigned int n)
    {
        for(unsigned int i=0; i < n; ++i) phItem->next();
        return *this;
    }


    /**
     *  compare operator
     */
    bool operator==(const ValueIterator& rhs) const {
        // If one of items is empty
        // The order of the following tests is optimized. Do not change it.
        if(!isEmpty() &&  rhs.isEmpty() ) return false;
        if( isEmpty() &&  rhs.isEmpty() ) return true;
        if( isEmpty() && !rhs.isEmpty() ) return false;

        // If both are not empty
        return phItem->compare(rhs.phItem);
    }

    bool operator!=(const ValueIterator& rhs) const {
        return !operator==(rhs);
    }

    HashItem& operator*() {
        return *phItem;
    }
    
    HashItem* operator->() {
        return phItem;
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

    // Position in the internal hash table. Pointer to HashItem
    HashItem *phItem;
};

/**
 *  End of namespace
 */
}
