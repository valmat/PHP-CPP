/**
 *  hashitemtraversable.cpp
 *
 *  HashItemTraversable
 *
 *  @copyright 2013 Copernica BV
 */
#include "includes.h"

/**
 *  Set up namespace
 */
namespace Php {

/**
 *  Constructor HashItemTraversable
 *  @param  arr HashTable
 */
HashItemTraversable::HashItemTraversable(zend_class_entry *ce, zval *pval)
{
    std::cout << "\x1b[0;36m\n HashItemTraversable::HashItemTraversable \n\x1b[0m";
    //ce = _ce;
    //funcs = ce->iterator_funcs.funcs;
    getIterator(ce, pval);
}


/**
 *  retrieve data value
 */
Value HashItemTraversable::value() const 
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
    //funcs->get_current_data(iter, &pval);
    // ZEND_API void zend_user_it_get_current_data(zend_object_iterator *_iter, zval ***data TSRMLS_DC);
    zend_user_it_get_current_data(iter, &pval);

    //void (*)(zend_object_iterator *iter, zval ***data TSRMLS_DC);
    //return Value(**ppretv);
    //return Value(*((zval **)value));
    return Value(*pval);
    

}

/**
 *  return key
 */
Value HashItemTraversable::key() const
{
    /* fetch the key for the current element (optional, may be NULL). The key
     * should be written into the provided zval* using the ZVAL_* macros. If
     * this handler is not provided auto-incrementing integer keys will be
     * used. */
    //void (*get_current_key)(zend_object_iterator *iter, zval *key TSRMLS_DC);
    std::cout << "\x1b[0;36m\n return key \n\x1b[0m";

    zval zv;
    //funcs->get_current_key(iter, &zv);
    // ZEND_API void zend_user_it_get_current_key(zend_object_iterator *_iter, zval *key TSRMLS_DC);
    zend_user_it_get_current_key(iter, &zv);

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
unsigned long HashItemTraversable::intKey() const
{
    std::cout << "\x1b[0;36m\n HashItemTraversable::intKey \n\x1b[0m";

    zval zv;
    //funcs->get_current_key(iter, &zv);
    zend_user_it_get_current_key(iter, &zv);
    return zv.value.lval;
}

/**
 *  return integer key (index)
 */
std::string HashItemTraversable::strKey() const
{
    std::cout << "\x1b[0;36m\n HashItemTraversable::strKey \n\x1b[0m";

    zval zv;
    //funcs->get_current_key(iter, &zv);
    zend_user_it_get_current_key(iter, &zv);
    return  std::string(zv.value.str.val, zv.value.str.len);
}

/**
 *  key type is string?
 */
bool HashItemTraversable::isstr() const
{
    std::cout << "\x1b[0;36m\n HashItemTraversable::isstr \n\x1b[0m";

    zval zv;
    //funcs->get_current_key(iter, &zv);
    zend_user_it_get_current_key(iter, &zv);
    return ( (Type)Z_TYPE(zv) == Type::String );   
}

/**
 *  is hashtable item is empty?
 */
bool HashItemTraversable::isEmpty() const
{
    std::cout << "\x1b[0;36m\n HashItemTraversable::isEmpty \n\x1b[0m";
    // check for end of iteration (FAILURE or SUCCESS if data is valid)
    // ZEND_API int zend_user_it_valid(zend_object_iterator *_iter TSRMLS_DC);
    //return ( FAILURE == funcs->valid(iter) );
    return ( FAILURE == zend_user_it_valid(iter) );
    
    /* invalidate current value/key (optional, may be NULL) */
    //void (*invalidate_current)(zend_object_iterator *iter TSRMLS_DC);
	// ZEND_API void zend_user_it_invalidate_current(zend_object_iterator *_iter TSRMLS_DC);

}

/**
 *  next iteration
 */
void HashItemTraversable::next()
{
    std::cout << "\x1b[0;36m\n HashItemTraversable::next \n\x1b[0m";
    // step forwards to next element
    //funcs->move_forward(iter);
    // ZEND_API void zend_user_it_move_forward(zend_object_iterator *_iter TSRMLS_DC);
    zend_user_it_move_forward(iter);
}

/**
 *  reset iterator to beginning of the hash table
 */
void HashItemTraversable::reset()
{
    std::cout << "\x1b[0;36m\n HashItemTraversable::reset \n\x1b[0m";
    // rewind to start of data (optional, may be NULL)
    //funcs->rewind(iter);
    // ZEND_API void zend_user_it_rewind(zend_object_iterator *_iter TSRMLS_DC);
    zend_user_it_rewind(iter);
}

/**
 *  compare operator
 */
bool HashItemTraversable::compare(const HashItem *rhs) const
{
    std::cout << "\x1b[0;36m\n HashItemTraversable::compare \n\x1b[0m";

    zval thisKey, thatKey;
    //funcs->get_current_key(iter, &thisKey);
    //((HashItemTraversable *)rhs)->funcs->get_current_key( ((HashItemTraversable *)rhs)->iter, &thatKey);
    zend_user_it_get_current_key(iter, &thisKey);
    zend_user_it_get_current_key( ((HashItemTraversable *)rhs)->iter, &thatKey);

    return (
                thisKey.type          == thatKey.type          && 
                thisKey.value.lval    == thatKey.value.lval    && 
                thisKey.value.str.len == thatKey.value.str.len &&
                thisKey.value.str.val == thatKey.value.str.val
           );
    return true;
}

void HashItemTraversable::getIterator(zend_class_entry *ce, zval *pval)
{
    std::cout << "\x1b[0;36m\n HashItemTraversable::getIterator \n\x1b[0m";
    //iter = ce->get_iterator(ce, pval, 0);

    //zend_object_iterator *iterator = zend_user_it_get_new_iterator(zend_class_entry *ce, zval *object, int by_ref);
    //zend_object_iterator *iterator = zend_user_it_get_new_iterator(ce, _val,0);
    //zval *iterator = zend_user_it_new_iterator(ce, object TSRMLS_CC);
    iter = zend_user_it_get_new_iterator(ce, pval,0);

    //iter->ce->iterator_funcs
    
    //std::cout << "\x1b[0;36m\n @@@ "<<  <<" \n\x1b[0m";
    std::cout << "\x1b[0;36m\n ce->iterator_funcs.funcs "<< ce->iterator_funcs.funcs <<" \n\x1b[0m";
    //std::cout << "\x1b[0;36m\n ce->iterator_funcs.funcs->rewind "<< ce->iterator_funcs.funcs->rewind <<" \n\x1b[0m";
    //std::cout << "\x1b[0;36m\n ce->iterator_funcs.funcs->zf_rewind "<< ce->iterator_funcs.funcs->zf_rewind <<" \n\x1b[0m";
    
    

}

HashItemTraversable::~HashItemTraversable()
{
    std::cout << "\x1b[0;36m\n DESTRUCT  ~HashItemTraversable \n\x1b[0m";
    // release all resources associated with this iterator instance
    //funcs->dtor(iter);

    // ##############
    
}

/**
 *  End of namespace
 */
}
