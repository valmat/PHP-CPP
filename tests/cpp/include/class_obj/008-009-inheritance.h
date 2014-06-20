/**
 *
 *  Test Classes and objects
 *	005-modifiers.phpt
 *
 */




/**
 *  Set up namespace
 */
namespace TestBaseClass {

   
    /**
     *  Test modifers
     */
    class TestImplInterf2 : public Php::Base
    {
    public:
        Php::Value method(Php::Parameters &params)
        { 
            Php::out << "TestImplInterf2::method" << std::endl;
            return nullptr;
        }
    };


/**
 *  End of namespace
 */
}

