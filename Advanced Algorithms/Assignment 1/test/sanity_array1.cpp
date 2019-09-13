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

TEST_CASE("Append") {
    dynamic_array_implementation test_dynamic_array;
    CHECK(test_dynamic_array.get_size() == 0);
    CHECK(test_dynamic_array.get_capacity() == 0);
    test_dynamic_array.append(5);
    CHECK(test_dynamic_array.get_size() == 1);
    CHECK(test_dynamic_array.get_capacity() == 1);
    test_dynamic_array.append(10);
    CHECK(test_dynamic_array.get_size() == 2);
    CHECK(test_dynamic_array.get_capacity() == 2);
    test_dynamic_array.append(15);
    CHECK(test_dynamic_array.get_size() == 3);
    CHECK(test_dynamic_array.get_capacity() == 4);
    test_dynamic_array.append(20);
    CHECK(test_dynamic_array.get_size() == 4);
    CHECK(test_dynamic_array.get_capacity() == 4);
    test_dynamic_array.append(25);
    CHECK(test_dynamic_array.get_size() == 5);
    CHECK(test_dynamic_array.get_capacity() == 8);
    test_dynamic_array.append(30);
    CHECK(test_dynamic_array.get_size() == 6);
    CHECK(test_dynamic_array.get_capacity() == 8);
    CHECK(test_dynamic_array.get(0) == 5);
    CHECK(test_dynamic_array.get(1) == 10);
    CHECK(test_dynamic_array.get(2) == 15);
    CHECK(test_dynamic_array.get(3) == 20);
    CHECK(test_dynamic_array.get(4) == 25);
    CHECK(test_dynamic_array.get(5) == 30);

}

TEST_CASE("Pop") {
    dynamic_array_implementation test_dynamic_array;
    CHECK(test_dynamic_array.get_size() == 0);
    CHECK(test_dynamic_array.get_capacity() == 0);
    test_dynamic_array.append(5);
    CHECK(test_dynamic_array.get_size() == 1);
    CHECK(test_dynamic_array.get_capacity() == 1);
    test_dynamic_array.append(10);
    CHECK(test_dynamic_array.get_size() == 2);
    CHECK(test_dynamic_array.get_capacity() == 2);
    test_dynamic_array.append(15);
    CHECK(test_dynamic_array.get_size() == 3);
    CHECK(test_dynamic_array.get_capacity() == 4);
    test_dynamic_array.append(20);
    CHECK(test_dynamic_array.get_size() == 4);
    CHECK(test_dynamic_array.get_capacity() == 4);
    test_dynamic_array.append(25);
    CHECK(test_dynamic_array.get_size() == 5);
    CHECK(test_dynamic_array.get_capacity() == 8);
    test_dynamic_array.append(30);
    CHECK(test_dynamic_array.get_size() == 6);
    CHECK(test_dynamic_array.get_capacity() == 8);
    CHECK(test_dynamic_array.get(0) == 5);
    CHECK(test_dynamic_array.get(1) == 10);
    CHECK(test_dynamic_array.get(2) == 15);
    CHECK(test_dynamic_array.get(3) == 20);
    CHECK(test_dynamic_array.get(4) == 25);
    CHECK(test_dynamic_array.get(5) == 30);

    test_dynamic_array.pop();
    CHECK(test_dynamic_array.get_size() == 5);
    CHECK(test_dynamic_array.get_capacity() == 8);
    CHECK(test_dynamic_array.get(4) == 25);
    test_dynamic_array.pop();
    CHECK(test_dynamic_array.get_size() == 4);
    CHECK(test_dynamic_array.get_capacity() == 8);
    CHECK(test_dynamic_array.get(3) == 20);
    test_dynamic_array.pop();
    CHECK(test_dynamic_array.get_size() == 3);
    CHECK(test_dynamic_array.get_capacity() == 8);
    CHECK(test_dynamic_array.get(2) == 15);
    test_dynamic_array.pop();
    CHECK(test_dynamic_array.get_size() == 2);
    CHECK(test_dynamic_array.get_capacity() == 4);
    CHECK(test_dynamic_array.get(1) == 10);
    test_dynamic_array.pop();
    CHECK(test_dynamic_array.get_size() == 1);
    CHECK(test_dynamic_array.get_capacity() == 2);
    CHECK(test_dynamic_array.get(0) == 5);

}
