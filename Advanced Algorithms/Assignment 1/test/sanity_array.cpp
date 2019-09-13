#include "../src/dynamic_array_implementation.cpp"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("Initialization") {
    dynamic_array_implementation test_dynamic_array;
    CHECK(test_dynamic_array.get_size() == 0);
    CHECK(test_dynamic_array.get_capacity() == 0);
}

TEST_CASE("Insert") {
    dynamic_array_implementation test_dynamic_array;
    test_dynamic_array.append(5);
    CHECK(test_dynamic_array.get_size() == 1);
    CHECK(test_dynamic_array.get_capacity() == 1);
    CHECK(test_dynamic_array.get(0) == 5);
}

TEST_CASE("Delete") {
    dynamic_array_implementation test_dynamic_array;
    test_dynamic_array.append(5);
    test_dynamic_array.pop();
    CHECK(test_dynamic_array.get_size() == 0);
    CHECK(test_dynamic_array.get_capacity() == 0);
}
TEST_CASE("Insert_Delete"){
    dynamic_array_implementation test_dynamic_array;
    test_dynamic_array.pop();
    CHECK(test_dynamic_array.get_size() == 0);
    CHECK(test_dynamic_array.get_capacity() == 0);
    test_dynamic_array.append(1);
	test_dynamic_array.append(2);
    CHECK(test_dynamic_array.get(1) == 2);
    CHECK(test_dynamic_array.get_size() == 2);
    CHECK(test_dynamic_array.get_capacity() == 2);
    test_dynamic_array.append(3);
    CHECK(test_dynamic_array.get_size() == 3);
    CHECK(test_dynamic_array.get_capacity() == 4);
	test_dynamic_array.append(4);
    test_dynamic_array.append(5);
    CHECK(test_dynamic_array.get_size() == 5);
    CHECK(test_dynamic_array.get_capacity() == 8);
	test_dynamic_array.append(6);
    test_dynamic_array.append(7);
	test_dynamic_array.append(8);
    test_dynamic_array.append(9);
	test_dynamic_array.append(10);
    CHECK(test_dynamic_array.get(12) == -1);
    test_dynamic_array.append(11);
	test_dynamic_array.append(12);
    test_dynamic_array.append(13);
    CHECK(test_dynamic_array.get(12) == 13);
	test_dynamic_array.append(14);
    test_dynamic_array.append(15);
	test_dynamic_array.append(16);	
	CHECK(test_dynamic_array.get_size() == 16);
    CHECK(test_dynamic_array.get_capacity() == 16);
	test_dynamic_array.pop();
	test_dynamic_array.pop();	
	test_dynamic_array.pop();
	test_dynamic_array.pop();
	test_dynamic_array.pop();
    CHECK(test_dynamic_array.get(8) == 9);
	test_dynamic_array.pop();
	test_dynamic_array.pop();
	test_dynamic_array.pop();
	CHECK(test_dynamic_array.get_size() == 8);
    CHECK(test_dynamic_array.get_capacity() == 16);
	test_dynamic_array.pop();
	test_dynamic_array.pop();
	test_dynamic_array.pop();
	test_dynamic_array.pop();
	CHECK(test_dynamic_array.get_size() == 4);
    CHECK(test_dynamic_array.get_capacity() == 8);
	test_dynamic_array.pop();
	test_dynamic_array.pop();
	CHECK(test_dynamic_array.get_size() == 2);
    CHECK(test_dynamic_array.get_capacity() == 4);
	test_dynamic_array.pop();			
	CHECK(test_dynamic_array.get_size() == 1);
    CHECK(test_dynamic_array.get_capacity() == 2);
	test_dynamic_array.pop();	
	CHECK(test_dynamic_array.get_size() == 0);
    CHECK(test_dynamic_array.get_capacity() == 0);
	test_dynamic_array.pop();	
	test_dynamic_array.pop();	
	test_dynamic_array.pop();	
    CHECK(test_dynamic_array.get(0) == -1);
	CHECK(test_dynamic_array.get_size() == 0);
    CHECK(test_dynamic_array.get_capacity() == 0);
}
