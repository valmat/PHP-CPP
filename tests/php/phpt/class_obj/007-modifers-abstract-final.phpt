--TEST--
Test class modifers: Abstract, Final
--SKIPIF--
<?php if (!extension_loaded("extension_for_tests")) print "skip"; ?>
--FILEEOF--
<?php

echo new ReflectionClass('TestBaseClass\TestAbstract');
echo new ReflectionClass('TestBaseClass\TestFinal');

--EXPECT--
Class [ <internal:extension_for_tests> abstract class TestBaseClass\TestAbstract ] {

  - Constants [0] {
  }

  - Static properties [0] {
  }

  - Static methods [0] {
  }

  - Properties [0] {
  }

  - Methods [0] {
  }
}
Class [ <internal:extension_for_tests> final class TestBaseClass\TestFinal ] {

  - Constants [0] {
  }

  - Static properties [0] {
  }

  - Static methods [0] {
  }

  - Properties [0] {
  }

  - Methods [0] {
  }
}