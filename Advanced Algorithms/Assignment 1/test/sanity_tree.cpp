#include "../src/splay_tree_implementation.cpp"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("Initialization") {
    splay_tree_implementation test_splay_tree;
    CHECK(test_splay_tree.get_num_nodes() == 0);
}

TEST_CASE("Insert") {
    splay_tree_implementation test_splay_tree;
    test_splay_tree.insert(1);
    CHECK(test_splay_tree.get_num_nodes() == 1);
}

TEST_CASE("Find") {
    splay_tree_implementation test_splay_tree;
    test_splay_tree.insert(1);
    CHECK(test_splay_tree.find(1) == true);    
}

TEST_CASE("Remove") {
    splay_tree_implementation test_splay_tree;
    test_splay_tree.insert(1);
    CHECK(test_splay_tree.get_num_nodes() == 1);
    test_splay_tree.remove(1);
    CHECK(test_splay_tree.get_num_nodes() == 0);
}

void VECTOR_CHECK(vector<int> v1, vector<int> v2)
{
    if(v1.size() != v2.size())
    {
        CHECK(v1.size() == v2.size());
        return;
    }
    for(int i = 0; i<v1.size(); i++)
    {
        CHECK(v1[i] == v2[i]);
    }
}

TEST_CASE("Root") {
    splay_tree_implementation test_splay_tree;
    test_splay_tree.insert(10);
    CHECK(test_splay_tree.get_num_nodes() == 1);
    vector<int> expected = {10};
    vector<int> obtained;
    obtained = test_splay_tree.pre_order();
    VECTOR_CHECK(expected, obtained);
    obtained = test_splay_tree.post_order();
    VECTOR_CHECK(expected, obtained);
}

TEST_CASE("Create") {
    splay_tree_implementation test_splay_tree;
    test_splay_tree.insert(100);
    CHECK(test_splay_tree.get_num_nodes() == 1);
    vector<int> expected = {100};
    vector<int> obtained;
    obtained = test_splay_tree.pre_order();
    VECTOR_CHECK(expected, obtained);
    obtained = test_splay_tree.in_order();
    VECTOR_CHECK(expected, obtained);
    obtained = test_splay_tree.post_order();
    VECTOR_CHECK(expected, obtained);

    test_splay_tree.insert(50);
    expected = {50, 100};
    obtained = test_splay_tree.in_order();
    CHECK(test_splay_tree.get_num_nodes() == 2);
    VECTOR_CHECK(expected, obtained);

    test_splay_tree.insert(25);
    expected = {25, 50, 100};
    obtained = test_splay_tree.in_order();
    CHECK(test_splay_tree.get_num_nodes() == 3);
    VECTOR_CHECK(expected, obtained);

    test_splay_tree.insert(65);
    expected = {25, 50, 65, 100};
    obtained = test_splay_tree.in_order();
    CHECK(test_splay_tree.get_num_nodes() == 4);
    VECTOR_CHECK(expected, obtained);

    test_splay_tree.insert(30);
    expected = {25, 30, 50, 65, 100};
    obtained = test_splay_tree.in_order();
    CHECK(test_splay_tree.get_num_nodes() == 5);
    VECTOR_CHECK(expected, obtained);

    test_splay_tree.insert(110);
    expected = {25, 30, 50, 65, 100, 110};
    obtained = test_splay_tree.in_order();
    CHECK(test_splay_tree.get_num_nodes() == 6);
    VECTOR_CHECK(expected, obtained);

    test_splay_tree.insert(45);
    expected = {25, 30, 45, 50, 65, 100, 110};
    obtained = test_splay_tree.in_order();
    CHECK(test_splay_tree.get_num_nodes() == 7);
    VECTOR_CHECK(expected, obtained);

    test_splay_tree.insert(45);
    expected = {25, 30, 45, 50, 65, 100, 110};
    obtained = test_splay_tree.in_order();
    CHECK(test_splay_tree.get_num_nodes() == 7);
    VECTOR_CHECK(expected, obtained);

    test_splay_tree.insert(45);
    obtained = test_splay_tree.pre_order();
    CHECK(obtained[0] == 45);
    test_splay_tree.insert(100);
    obtained = test_splay_tree.pre_order();
    CHECK(obtained[0] == 100);
    test_splay_tree.insert(25);
    obtained = test_splay_tree.pre_order();
    CHECK(obtained[0] == 25);
    test_splay_tree.insert(50);
    obtained = test_splay_tree.pre_order();
    CHECK(obtained[0] == 50);

}

TEST_CASE("Delete") {
    splay_tree_implementation test_splay_tree;
    test_splay_tree.insert(100);
    CHECK(test_splay_tree.get_num_nodes() == 1);
    vector<int> expected = {100};
    vector<int> obtained;
    obtained = test_splay_tree.in_order();
    VECTOR_CHECK(expected, obtained);
    test_splay_tree.insert(50);
    CHECK(test_splay_tree.get_num_nodes() == 2);
    expected = {50, 100};
    obtained = test_splay_tree.in_order();
    VECTOR_CHECK(expected, obtained);
    test_splay_tree.remove(150);
    CHECK(test_splay_tree.get_num_nodes() == 2);
    obtained = test_splay_tree.pre_order();
    CHECK(obtained[0] == 100);
    test_splay_tree.insert(25);
    CHECK(test_splay_tree.get_num_nodes() == 3);
    obtained = test_splay_tree.in_order();
    expected = {25, 50, 100};
    VECTOR_CHECK(expected, obtained);
    test_splay_tree.remove(100);
    CHECK(test_splay_tree.get_num_nodes() == 2);
    obtained = test_splay_tree.pre_order();
    CHECK(obtained[0] == 50);
    test_splay_tree.remove(50);
    CHECK(test_splay_tree.get_num_nodes() == 1);
    obtained = test_splay_tree.in_order();
    expected = {25};
    VECTOR_CHECK(expected, obtained);

}