/**
 *  hashitemiterator.h
 *
 *  HashItemIterator
 *
 *  @copyright 2013 Copernica BV
 */
#ifndef HASHITEMITERATOR_H
#define HASHITEMITERATOR_H



/**
 *  Forward declaration
 */
struct _zend_object_iterator;
struct _zend_object_iterator_funcs;

/**
 *  Set up namespace
 */
namespace Php {

/**
 *  Class definition
 *  HashItemIterator
 */
class HashItemIterator : public HashItem
{
public:

    /**
     *  Constructor HashItemIterator
     *  @param  arr HashTable
     */
    //explicit HashItemIterator(_zend_object_iterator *it) :  {}
    HashItemIterator(_zend_class_entry* ce, _zval_struct* val);

    /**
     *  retrieve data value
     */
    virtual Value value() const override;

    /**
     *  return key
     */
    virtual Value key() const override;

    /**
     *  return integer key (index)
     */
    virtual unsigned long intKey() const override;

    /**
     *  return integer key (index)
     */
    virtual std::string strKey() const override;

    /**
     *  key type is string?
     */
    virtual bool isstr() const override;

    /**
     *  is hashtable item is empty?
     */
    virtual bool isEmpty() const override;

    /**
     *  next iteration
     */
    virtual void next() override;

    /**
     *  reset iterator to beginning of the hash table
     */
    virtual void reset() override;

    /**
     *  compare operator
     */
    //virtual bool compare(const HashItem& rhs) const;
    virtual bool compare(const HashItem *rhs) const override;



    //virtual ~HashItemIterator() {};
    virtual ~HashItemIterator();

private:

	virtual void getIterator(_zend_class_entry *ce, _zval_struct *pval);

	// Internal iterator of iterable object
	_zend_object_iterator *iter;
	//_zend_class_entry *ce;
	_zend_object_iterator_funcs *funcs;
    
};

/**
 *  End of namespace
 */
}
#endif /* HashItemIterator.h */
