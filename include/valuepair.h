/**
 *  valuepair.h
 *
 *  
 *  
 *
 *  @copyright 2013 Copernica BV
 */
#ifndef VALUEPAIR_H
#define VALUEPAIR_H

/**
 *  Set up namespace
 */
namespace Php {

/**
 *  
 *  
 */
class ValuePair
{
private:


    //ValuePair(unsigned long i, std::string k, Value v, bool type = true): _ind(i), _key(k), _value(v), isString(type)  {};
    //ValuePair(unsigned long i, const char* k, Value v, bool type = true): _ind(i), _key(k), _value(v), isString(type)  {};
    //ValuePair(unsigned long i, const char* k, void ** v, bool type = true): _ind(i), _key(k), _value(v), isString(type)  {};


    /*
    ValuePair(const ValuePair& that) : _ind(that._ind) {}
    ValuePair(ValuePair&& that) : _ind(std::move(that._ind)) {}
    ValuePair &operator=(const ValuePair& that) {
        _ind = that._ind;
    }
    ValuePair &operator=(ValuePair&& that) {
        _ind = std::move(that._ind);
    }
    */
public:

    //return _value;
    Value value() const {
        return Value(*_value);
    }

    //return string key
    std::string key() const {
        return isString ? _key : std::to_string(_ind);
    }

    //return integer key (index)
    unsigned long ind() const {
        return _ind;
    }

    // key type is string?
    bool isstr() const {
        return isString;
    }

    // debug function.
    const char *typestr() const {return isString ? "str" : "num";}

private:
    
    /**
     *  Constructor.
     *  only ValueIterator can create object of ValuePair
     */
    ValuePair(): _ind(0), _key(""), isString(false), _value(nullptr) {}

    /**
     *  Reset to empty.
     *  If ValuePair oject is empty, then the containing it ValueIterator object == ValueIterator::null
     */
    void reset() {
        _ind = 0;
        _key = "";
    }

    unsigned long _ind;
    
    const char*   _key;

    //zval** _value;
    struct _zval_struct** _value;

    // key type is string?
    bool isString;

friend class ValueIterator;
};

/**
 *  End of namespace
 */
}
#endif /* valuepair.h */
