--TEST--
Extend class
--SKIPIF--
<?php if (!extension_loaded("extension_for_tests")) print "skip"; ?>
--FILEEOF--
<?php

echo new ReflectionClass('TestBaseClass\TestImplInterf3');

--EXPECT--
Class [ <internal:extension_for_tests> class TestBaseClass\TestImplInterf3 extends TestBaseClass\TestImplInterf2 implements TestBaseClass\TestInterface ] {

  - Constants [0] {
  }

  - Static properties [0] {
  }

  - Static methods [0] {
  }

  - Properties [0] {
  }

  - Methods [1] {
    Method [ <internal:extension_for_tests, inherits TestBaseClass\TestImplInterf2, prototype TestBaseClass\TestInterface> public method myMethod ] {

      - Parameters [1] {
        Parameter #0 [ <required> $value ]
      }
    }
  }
}

