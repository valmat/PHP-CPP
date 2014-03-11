/**
 *  valueiterator.h
 *
 *  
 *  
 *
 *  @copyright 2013 Copernica BV
 */
#ifndef VALUEITERATOR_H
#define VALUEITERATOR_H

/**
 *  Forward declaration
 */
struct _hashtable;

/**
 *  Set up namespace
 */
namespace Php {

/**
 *  
 *  
 */
class ValueIterator
{
public:
    
    ValueIterator() {
        _pair.reset();
    }

    /**
     *  Constructor ValueIterator
     *  @param  arr HashTable
     */
    ValueIterator(_hashtable *arr, bool isArray);

    /**
     *  Copy Constructor
     */
    ValueIterator(const ValueIterator& that) : _arr(that._arr), _pair(that._pair), _isArray(that._isArray) {}

    /**
     *  Move Constructor
     */
    ValueIterator(ValueIterator&& that) :  _arr(std::move(that._arr)), _pair(std::move(that._pair)), _isArray(that._isArray) {}



    /*
    ValueIterator &operator=(ValueIterator &&that) {
        if (this == &that) return *this;
        p = that.p;
        return *this;
    }
    ValueIterator &operator=(const ValueIterator &that) {
        if (this == &that) return *this;
        p = that.p;
        that.p = nullptr;
        return *this;
    }
    */

    /**
     *  Increment operator
     */
    ValueIterator& operator++() {
        nextIteration();
        setPair();
        return *this;
    }

    ValueIterator operator++(int) {
        ValueIterator tmp(*this);
        operator++();
        return tmp;
    }

    bool operator==(const ValueIterator& rhs) const {
        return (_pair._ind == rhs._pair._ind && _pair._key==rhs._pair._key );
    }

    bool operator!=(const ValueIterator& rhs) const {
        return !operator==(rhs);
    }

    //explicit T& operator*() {return *p;}
    ValuePair& operator*() {
        return _pair;
    }
    
    ValuePair* operator ->() {
        return &_pair;
    }

    static ValueIterator null;

private:
    /**
     *  Retrieving data from `HashTable arr` and filling in the `ValuePair _pair`
     */
    void setPair();
    /**
     *  next iteration
     */
    void nextIteration();
    

    ValuePair _pair;

    _hashtable *_arr;
    bool _isArray;

    
};
//extern ValueIterator ValueIterator::null;


/**
 *  End of namespace
 */
}
#endif /* valueiterator.h */
