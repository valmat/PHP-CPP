--TEST--
Implement interface
--SKIPIF--
<?php if (!extension_loaded("extension_for_tests")) print "skip"; ?>
--FILEEOF--
<?php

echo new ReflectionClass('TestBaseClass\TestInterface'), PHP_EOL;
echo new ReflectionClass('TestBaseClass\TestImplInterf1'), PHP_EOL;
echo new ReflectionClass('TestBaseClass\TestImplInterf2'), PHP_EOL;

--EXPECT--
Interface [ <internal:extension_for_tests> interface TestBaseClass\TestInterface ] {

  - Constants [0] {
  }

  - Static properties [0] {
  }

  - Static methods [0] {
  }

  - Properties [0] {
  }

  - Methods [1] {
    Method [ <internal:extension_for_tests> abstract public method myMethod ] {

      - Parameters [1] {
        Parameter #0 [ <required> $value ]
      }
    }
  }
}

Class [ <internal:extension_for_tests> class TestBaseClass\TestImplInterf1 implements TestBaseClass\TestInterface ] {

  - Constants [0] {
  }

  - Static properties [0] {
  }

  - Static methods [0] {
  }

  - Properties [0] {
  }

  - Methods [1] {
    Method [ <internal:extension_for_tests, inherits TestBaseClass\TestInterface> abstract public method myMethod ] {

      - Parameters [1] {
        Parameter #0 [ <required> $value ]
      }
    }
  }
}

Class [ <internal:extension_for_tests> class TestBaseClass\TestImplInterf2 implements TestBaseClass\TestInterface ] {

  - Constants [0] {
  }

  - Static properties [0] {
  }

  - Static methods [0] {
  }

  - Properties [0] {
  }

  - Methods [1] {
    Method [ <internal:extension_for_tests, prototype TestBaseClass\TestInterface> public method myMethod ] {

      - Parameters [1] {
        Parameter #0 [ <required> $value ]
      }
    }
  }
}