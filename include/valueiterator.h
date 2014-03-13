/**
 *  valueiterator.h
 *
 *  ValueIterator - designed for natural iteration objects and arrays of type Value. 
 *  it does not use STL containers and carries minimal overhead.
 *
 *  @copyright 2013 Copernica BV
 */
#ifndef VALUEITERATOR_H
#define VALUEITERATOR_H

/**
 *  Set up namespace
 */
namespace Php {

/**
 *  Class definition
 */
class ValueIterator
{
public:
    
    /**
     *  Constructor for empty ValueIterator.
     *  Used only for build ValueIterator::null
     */
    ValueIterator() : htItem() {}

    /**
     *  Constructor ValueIterator
     *  @param  arr HashTable
     */
    explicit ValueIterator(_hashtable *arr): htItem(arr) {
        reset();
    }

    /**
     *  Copy Constructor
     */
    //ValueIterator(const ValueIterator& that) : htItem(that.htItem) {}

    /**
     *  Move Constructor
     */
    //ValueIterator(ValueIterator&& that) : htItem(std::move(that.htItem)) {}

    /**
     *  Increment operator
     */
    ValueIterator& operator++() {
        htItem.next();
        return *this;
    }

    ValueIterator operator++(int) {
        ValueIterator tmp(*this);
        operator++();
        return tmp;
    }

    bool operator==(const ValueIterator& rhs) const {
        return (htItem == rhs.htItem);
    }

    bool operator!=(const ValueIterator& rhs) const {
        return !operator==(rhs);
    }

    HTwrapper& operator*() {
        return htItem;
    }
    
    HTwrapper* operator ->() {
        return &htItem;
    }

    // Сделать потом эту функцию виртуальной
    void reset() {
        htItem.toBegin();
    }

    // Empty iterator. Used to finish the iterations
    static ValueIterator null;

private:

    // Position in the internal hash table
    HTwrapper htItem;
    
};





/**
 *  End of namespace
 */
}
#endif /* valueiterator.h */
