// 010-TestCase.cpp

// Let Catch provide main():
#define CATCH_CONFIG_MAIN

#include "catch/catch.hpp"
#include "../src/my_class.cpp"

TEST_CASE("Test placeholder. PASS.")
{
	REQUIRE (MyClass::foo() == 12);
}

// Compile & run:
// g++ -std=c++17 -Wall -Itest/catch/catch.hpp -o test/TestCase test/TestCase.cpp && test/TestCase --success