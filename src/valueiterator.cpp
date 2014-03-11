/**
 *  valueiterator.cpp
 *
 *  
 *  
 *
 *  @copyright 2013 Copernica BV
 */
#include "includes.h"

/**
 *  Set up namespace
 */
namespace Php {

/**
 *  
 *  
 */
//ValueIterator ValueIterator::null;

/**
 *  Constructor ValueIterator
 *  @param  arr HashTable
 */
ValueIterator::ValueIterator(_hashtable *arr, bool isArray): _arr(arr), _isArray(isArray) {
    // reset iterator to beginning of the hash table
    zend_hash_internal_pointer_reset(arr);

    // filling _pair
    setPair();
}

/**
 *  Retrieving data from `HashTable arr` and filling in the `ValuePair _pair`
 */
void ValueIterator::setPair() {
    // pointer that will be set to hash key or index
    char *key;
    unsigned long ind;

    // get current key
    int hash_key_type = zend_hash_get_current_key(_arr, &key, &ind, 0);

    // if data NO exist
    if(HASH_KEY_NON_EXISTENT == hash_key_type) {
        _pair.reset();
        return;
    }

    // required variable (array value)
    zval **value;

    // retrieve data, and add to result
    zend_hash_get_current_data(_arr, (void **) &value);

    // check Value type
    if (_isArray)
    {
        // check key type
        if (HASH_KEY_IS_STRING == hash_key_type) {
            _pair.isString = true;
            _pair._key     = key;
            _pair._ind     = 0;

        } else {
            _pair.isString = false;
            //_pair._key     = std::to_string(ind);
            _pair._key     = "";
            _pair._ind     = ind;
        }

        //_pair._value = std::move(Value(*value));
        //zval_add_ref(value);
        //_pair._value = Value(*value);
        _pair._value = value;
        //_pair._value = (void **)&value;
    }
    /*
    else
    {
            // check the type
            switch (hash_key_type) {
            
            // was it a string?
            case HASH_KEY_IS_STRING:

                // inaccessible properties (privates) start with a null character
                if (*key == '\0') break;

                // required variable
                zval **value;

                // retrieve data, and add to result
                zend_hash_get_current_data(_arr, (void **) &value);
                result[key] = Value(*value);
                break;
                
            default:
            
                // we're ready
                return result;
            }
    }
    */

}

/**
 *  next iteration
 */
void ValueIterator::nextIteration() {
    zend_hash_move_forward(_arr);
}
            

/**
 *  End of namespace
 */
}
