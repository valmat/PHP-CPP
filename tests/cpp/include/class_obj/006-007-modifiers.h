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
    class TestModifers : public Php::Base
    {
    public:
        /**
         *  C++ constructor and destructor
         */
        TestModifers() {}
        virtual ~TestModifers() {}


        void testPublic() 
        { 
            Php::out << "Public" << std::endl;
        }

        void testProtected() 
        { 
            Php::out << "Protected" << std::endl;
        }

        void testPrivate() 
        { 
            Php::out << "Private" << std::endl;
        }

        void testFinal() 
        { 
            Php::out << "Final" << std::endl;
        }

    };

    class EmptyClass : public Php::Base {};


/**
 *  End of namespace
 */
}

