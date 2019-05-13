1. clone or download test lib from https://github.com/google/googletest
2. we need only googletest folder content. 
type
``` 
set GTEST_DIR=<googletest_location>
```
were googletest_location is a path for googletest folder

3. at working dir (where main.cpp is located) type 
```
g++ -std=c++11 -isystem ${GTEST_DIR}/include -I${GTEST_DIR} -pthread -c ${GTEST_DIR}/src/gtest-all.cc 
```

and then type
```
mkdir bin
ar -rv bin/libgtest.a gtest-all.o
```

expected result is a libgtest.a file at bin dir

4. build our tests
type
```
g++ -std=c++11 -isystem ${GTEST_DIR}/include -pthread -Isrc/ src/main.cpp tests/nvector_tests.cpp bin/libgtest.a
```

expected a.out file as result

5. run a.out

expected result is something like
```
hello, Nykytich! Let try to run all tests...
[==========] Running 1 test from 1 test suite.
[----------] Global test environment set-up.
[----------] 1 test from base_test
[ RUN      ] base_test.chacking_test
[       OK ] base_test.chacking_test (0 ms)
[----------] 1 test from base_test (0 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test suite ran. (0 ms total)
[  PASSED  ] 1 test.
```
