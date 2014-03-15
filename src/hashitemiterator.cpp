/**
 *  hashitemiterator.cpp
 *
 *  HashItemIterator
 *
 *  @copyright 2013 Copernica BV
 */
#include "includes.h"

/**
 *  Set up namespace
 */
namespace Php {

/**
 *  Constructor HashItemIterator
 *  @param  arr HashTable
 */
HashItemIterator::HashItemIterator(zend_class_entry *ce, zval *pval)
//HashItemIterator(zend_object_iterator *it)
{
    std::cout << "\x1b[0;36m\n HashItemIterator::HashItemIterator \n\x1b[0m";
    //ce = _ce;
    funcs = ce->iterator_funcs.funcs;
    getIterator(ce, pval);
}


/**
 *  retrieve data value
 */
Value HashItemIterator::value() const 
{

    std::cout << "\x1b[0;36m\n return value \n\x1b[0m";

    //return Value("constVal");


    //zval **value;
    //zend_hash_get_current_data_ex(ht, (void **) &value, &pos);
    //return Value(*value);

    //zval_add_ref((zval **)pos->pData);
    //return Value(*((zval **)pos->pData));



    // fetch the item data for the current element
    //zval **value;
    zval **pval;
    //funcs->get_current_data(iter, (zval ***)&value);
    funcs->get_current_data(iter, &pval);

    //void (*)(zend_object_iterator *iter, zval ***data TSRMLS_DC);
    //return Value(**ppretv);
    //return Value(*((zval **)value));
    return Value(*pval);
    

}

/**
 *  return key
 */
Value HashItemIterator::key() const
{
    /* fetch the key for the current element (optional, may be NULL). The key
     * should be written into the provided zval* using the ZVAL_* macros. If
     * this handler is not provided auto-incrementing integer keys will be
     * used. */
    //void (*get_current_key)(zend_object_iterator *iter, zval *key TSRMLS_DC);
    std::cout << "\x1b[0;36m\n return key \n\x1b[0m";

    zval zv;
    funcs->get_current_key(iter, &zv);

    Type tp = (Type)Z_TYPE(zv);
    //std::cout << "\x1b[1;32m\n zv.type "<< ((Type)Z_TYPE(zv) == Type::Numeric) ? "n" : "s" <<" \n\x1b[0;0m";
    std::cout << "\x1b[1;32m\n zv.type "<< ( (tp == Type::Numeric) ? "n" : "s" ) <<" \n\x1b[0;0m";
    std::cout << "\x1b[1;32m\n zv.value.lval "<< zv.value.lval <<" \n\x1b[0;0m";
    std::cout << "\x1b[1;32m\n zv.value.str.val "<< zv.value.str.val <<" \n\x1b[0;0m";
    std::cout << "\x1b[1;32m\n zv.value.str.len "<< zv.value.str.len <<" \n\x1b[0;0m";

    

    /*
    zv.type
    zv.value.lval
    zv.value.str.val
    zv.value.str.len
    */



    Value retv(&zv);

    // @todo May be the following line can be done better?
    return retv.clone();
}

/**
 *  return integer key (index)
 */
unsigned long HashItemIterator::intKey() const
{
    std::cout << "\x1b[0;36m\n HashItemIterator::intKey \n\x1b[0m";

    zval zv;
    funcs->get_current_key(iter, &zv);
    return zv.value.lval;
}

/**
 *  return integer key (index)
 */
std::string HashItemIterator::strKey() const
{
    std::cout << "\x1b[0;36m\n HashItemIterator::strKey \n\x1b[0m";

    zval zv;
    funcs->get_current_key(iter, &zv);
    return  std::string(zv.value.str.val, zv.value.str.len);
}

/**
 *  key type is string?
 */
bool HashItemIterator::isstr() const
{
    std::cout << "\x1b[0;36m\n HashItemIterator::isstr \n\x1b[0m";
    // #####TODO

    zval zv;
    funcs->get_current_key(iter, &zv);

    /*
    Type tp = (Type)Z_TYPE(zv);
    Type keyType = Type::Null;
    long lval;                  
    double dval;                
    struct {
        char *val;
        int len;
    zv.type
    zv.value.lval
    zv.value.str.val
    zv.value.str.len
    */

    return ( (Type)Z_TYPE(zv) == Type::String );   
}

/**
 *  is hashtable item is empty?
 */
bool HashItemIterator::isEmpty() const
{
    std::cout << "\x1b[0;36m\n HashItemIterator::isEmpty \n\x1b[0m";
    // check for end of iteration (FAILURE or SUCCESS if data is valid)
    return ( FAILURE == funcs->valid(iter) );

    /* invalidate current value/key (optional, may be NULL) */
    //void (*invalidate_current)(zend_object_iterator *iter TSRMLS_DC);

}

/**
 *  next iteration
 */
void HashItemIterator::next()
{
    std::cout << "\x1b[0;36m\n HashItemIterator::next \n\x1b[0m";
    // step forwards to next element
    funcs->move_forward(iter);
}

/**
 *  reset iterator to beginning of the hash table
 */
void HashItemIterator::reset()
{
    std::cout << "\x1b[0;36m\n HashItemIterator::reset \n\x1b[0m";
    // rewind to start of data (optional, may be NULL)
    funcs->rewind(iter);
}

/**
 *  compare operator
 */
bool HashItemIterator::compare(const HashItem *rhs) const
{
    std::cout << "\x1b[0;36m\n HashItemIterator::compare \n\x1b[0m";

    zval thisKey, thatKey;
    funcs->get_current_key(iter, &thisKey);
    ((HashItemIterator *)rhs)->funcs->get_current_key( ((HashItemIterator *)rhs)->iter, &thatKey);

    return (
                thisKey.type          == thatKey.type          && 
                thisKey.value.lval    == thatKey.value.lval    && 
                thisKey.value.str.len == thatKey.value.str.len &&
                thisKey.value.str.val == thatKey.value.str.val
           );
    return true;
}

void HashItemIterator::getIterator(zend_class_entry *ce, zval *pval)
{
    std::cout << "\x1b[0;36m\n HashItemIterator::getIterator \n\x1b[0m";
    iter = ce->get_iterator(ce, pval, 0);
}

HashItemIterator::~HashItemIterator()
{
    std::cout << "\x1b[0;36m\n DESTRUCT  ~HashItemIterator \n\x1b[0m";
    // release all resources associated with this iterator instance
    funcs->dtor(iter);
}

/**
 *  End of namespace
 */
}
