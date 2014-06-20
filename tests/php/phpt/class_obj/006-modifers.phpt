--TEST--
Test member modifers
--SKIPIF--
<?php if (!extension_loaded("extension_for_tests")) print "skip"; ?>
--FILEEOF--
<?php

$ref = new ReflectionClass('TestBaseClass\TestModifers');
echo $ref;

$test = new TestBaseClass\TestModifers();

$test->testPublic();
$test->testProtected();
$test->testPrivate();
$test->testFinal();


--EXPECTF--
Class [ <internal:extension_for_tests> class TestBaseClass\TestModifers ] {

  - Constants [0] {
  }

  - Static properties [0] {
  }

  - Static methods [0] {
  }

  - Properties [0] {
  }

  - Methods [4] {
    Method [ <internal:extension_for_tests> public method testPublic ] {

      - Parameters [0] {
      }
    }

    Method [ <internal:extension_for_tests> protected method testProtected ] {

      - Parameters [0] {
      }
    }

    Method [ <internal:extension_for_tests> private method testPrivate ] {

      - Parameters [0] {
      }
    }

    Method [ <internal:extension_for_tests> final public method testFinal ] {

      - Parameters [0] {
      }
    }
  }
}
Public%w
Fatal error: Call to protected method TestBaseClass\TestModifers::testProtected() from context '' in %s on line %d