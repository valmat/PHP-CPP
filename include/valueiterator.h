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
    /*
    virtual ValueIterator& operator++() {
        std::cout << "\x1b[0;31m\n ValueIterator& operator++() \n\x1b[0m";
        htItem.next();
        return *this;
    }
    */
    virtual ValueIterator& operator++() {
        return prefix_inc();
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

    virtual ~ValueIterator() {}

    // Empty iterator. Used to finish the iterations
    static ValueIterator null;

protected:

    virtual ValueIterator& prefix_inc() {
        std::cout << "\x1b[0;31m\n ValueIterator& operator++() \n\x1b[0m";
        htItem.next();
        return *this;
    }

    // Position in the internal hash table
    HTwrapper htItem;
    
};

class ArrayIterator : public ValueIterator
{
public:
    ArrayIterator() : ValueIterator() {};
    ArrayIterator(_hashtable *arr): ValueIterator(arr) {std::cout << "\x1b[0;32m\n ArrayIterator \n\x1b[0m";}
    //ArrayIterator( ValueIterator& it ) : ValueIterator( it ) {}

    virtual ~ArrayIterator() {}
};

class ObjectIterator : public ValueIterator
{
public:
    ObjectIterator() : ValueIterator() {}
    ObjectIterator(_hashtable *arr): ValueIterator(arr) {std::cout << "\x1b[0;32m\n ObjectIterator \n\x1b[0m";}
    //ObjectIterator( ValueIterator& it ) : ValueIterator( it ) {}

    virtual ObjectIterator& operator++() { return (ObjectIterator &)ObjectIterator::prefix_inc(); }

    
private:

     
     
    virtual ValueIterator& prefix_inc() override {
        char a = htItem.isstr() ? 'y' : 'n';
        std::cout << "\x1b[0;31m\n ObjectIterator& operator++() \n\x1b[0m";
        std::cout << "\x1b[0;31m\n isstr: "<< a <<" \n\x1b[0m";

        htItem.next();
        return *this;

/*
        if ('\0' == *key) {
            next();
            setPair();
            return;
        }
*/

    }

    virtual ~ObjectIterator() {}

};



/**
 *  End of namespace
 */
}
#endif /* valueiterator.h */
