/**
 *  hashitemaggregate.cpp
 *
 *
 *  HashItemAggregate - allows iterate objects of a class that implements the PHP Aggregate interface
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
 *  Constructor HashItemAggregate
 *  @param  arr HashTable
 */
HashItemAggregate::HashItemAggregate(zend_class_entry *ce, zval *pval)
{
	iter = zend_user_it_get_new_iterator(ce, pval,0);
}

/**
 *  retrieve data value
 */
Value HashItemAggregate::value() const 
{
    // fetch the item data for the current element
    zval **pval;
    zend_user_it_get_current_data(iter, &pval);

    return *pval;
}

/**
 *  return key
 */
Value HashItemAggregate::key() const
{
    // fetch the key for the current element. 
    // The key should be written into the provided zval* using the ZVAL_* macros.
    // If this handler is not provided auto-incrementing integer keys will be used.
    zval zv;
    zend_user_it_get_current_key(iter, &zv);
    Value retv(&zv);

    // @todo May be the following line can be done better?
    return retv.clone();
}

/**
 *  return integer key (index)
 */
unsigned long HashItemAggregate::intKey() const
{
    zval zv;
    zend_user_it_get_current_key(iter, &zv);
    return zv.value.lval;
}

/**
 *  return string key
 */
std::string HashItemAggregate::strKey() const
{
    zval zv;
    zend_user_it_get_current_key(iter, &zv);
    return  std::string(zv.value.str.val, zv.value.str.len);
}

/**
 *  key type is string?
 */
bool HashItemAggregate::isstr() const
{
    zval zv;
    zend_user_it_get_current_key(iter, &zv);
    return ( (Type)Z_TYPE(zv) == Type::String );   
}

/**
 *  item on current position of hashtable is empty?
 */
bool HashItemAggregate::isEmpty() const
{
    // check for end of iteration (FAILURE or SUCCESS if data is valid)
    return ( FAILURE == zend_user_it_valid(iter) );
}

/**
 *  next iteration
 */
void HashItemAggregate::next()
{
    // step forwards to next element
    zend_user_it_move_forward(iter);
}

/**
 *  reset iterator to beginning of the hash table
 */
void HashItemAggregate::reset()
{
    // rewind to start of data
    zend_user_it_rewind(iter);
}

/**
 *  compare operator
 */
bool HashItemAggregate::compare(const HashItem *rhs) const
{
    zval thisKey, thatKey;
    zend_user_it_get_current_key(iter, &thisKey);
    zend_user_it_get_current_key( ((HashItemAggregate *)rhs)->iter, &thatKey);

    return (
                thisKey.type          == thatKey.type          && 
                thisKey.value.lval    == thatKey.value.lval    && 
                thisKey.value.str.len == thatKey.value.str.len &&
                thisKey.value.str.val == thatKey.value.str.val
           );
    return true;
}

/**
 *  End of namespace
 */
}
