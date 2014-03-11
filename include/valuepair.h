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
    ValuePair(): _ind(0), _key(""), isString(false)
    , _value(nullptr) 
    //, _value(0) 
    {
        //_value.setType(Type::Null);
    };

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
    //~ValuePair() = default;

    Value value() const {
        //return _value;
        return Value(*_value);
        //return Value(_value);
    }

    std::string key() const {
        //return _key;
        return isString ? _key : std::to_string(_ind).c_str();
    }

    unsigned long ind() const {
        return _ind;
    }

    bool isstr() const {
        return isString;
    }

    const char *typestr() const {return isString ? "str" : "num";}

private:
    void reset() {
        _ind = 0;
        _key = "";
    }

    unsigned long _ind;
    //std::string   _key;
    const char*   _key;
    //Value         _value;
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
