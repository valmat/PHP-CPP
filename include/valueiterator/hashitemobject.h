/**
 *  hashitemobject.h
 *
 *  HashItemObject
 *
 *  @copyright 2013 Copernica BV
 */
#ifndef HASHITEMOBJECT_H
#define HASHITEMOBJECT_H

/**
 *  Set up namespace
 */
namespace Php {

/**
 *  Class definition
 *  HashItemObject
 */
class HashItemObject : public HashItemArray
{
public:

    /**
     *  Constructor HashItemObject
     *  @param  arr HashTable
     */
     explicit HashItemObject(_hashtable *arr) : HashItemArray(arr) {}

    /**
     *  next iteration
     */
    virtual void next() override
    {
        HashPos.next();
        // check access rights to the current item
        checkAccess();
    }

    /**
     *  reset iterator to beginning of the hash table
     */
    virtual void reset() override
    {
        HashPos.toBegin();
        // After a reset key positions verifiable access rights to the first item
        checkAccess();
    }

    /**
     *  compare operator
     */
    virtual bool compare(const HashItem *rhs) const override
    {
        return (HashPos == ((HashItemObject *)rhs)->HashPos);
    }

    virtual ~HashItemObject() {};

private:

    /**
     *  Check the permissions of property. And move on to the next property, if access is denied.
     */
    void checkAccess()
    {
        if ( !HashPos.isEmpty() && !HashPos.keyAccessible() ) next();
    }
    
    // Position in the internal hash table
    //HashPositionWrapper HashPos;
};

/**
 *  End of namespace
 */
}
#endif /* hashitemobject.h */
