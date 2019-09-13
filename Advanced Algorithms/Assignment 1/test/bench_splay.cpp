#include "../src/splay_tree_implementation.cpp"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <chrono> 

using namespace std::chrono;

TEST_CASE("1% 10000 Keys") {
    splay_tree_implementation test_splay_tree;
    int inserted;
    for(int i=0; i<10000; i++)
    {
        inserted = rand()%10000;
        test_splay_tree.insert(inserted);
    }
    auto start = high_resolution_clock::now();
    for(int i = 0; i<100; i++)
    {
        test_splay_tree.find(rand()%100);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "1% 10000 Keys: " << duration.count() << endl;
}

TEST_CASE("10% 10000 Keys") {
    splay_tree_implementation test_splay_tree;
    int inserted;
    for(int i=0; i<10000; i++)
    {
        inserted = rand()%10000;
        test_splay_tree.insert(inserted);
    }
    auto start = high_resolution_clock::now();
    for(int i = 0; i<100; i++)
    {
        test_splay_tree.find(rand()%1000);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "10% 10000 Keys: " << duration.count() << endl;
}

TEST_CASE("50% 10000 Keys") {
    splay_tree_implementation test_splay_tree;
    int inserted;
    for(int i=0; i<10000; i++)
    {
        inserted = rand()%10000;
        test_splay_tree.insert(inserted);
    }
    auto start = high_resolution_clock::now();
    for(int i = 0; i<100; i++)
    {
        test_splay_tree.find(rand()%5000);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "50% 10000 Keys: " << duration.count() << endl;
}

TEST_CASE("100% 10000 Keys") {
    splay_tree_implementation test_splay_tree;
    int inserted;
    for(int i=0; i<10000; i++)
    {
        inserted = rand()%10000;
        test_splay_tree.insert(inserted);
    }
    auto start = high_resolution_clock::now();
    for(int i = 0; i<100; i++)
    {
        test_splay_tree.find(rand()%10000);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "100% 10000 Keys: " << duration.count() << endl; 
}

TEST_CASE("1% 100,000 Keys") {
    splay_tree_implementation test_splay_tree;
    int inserted;
    for(int i=0; i<100000; i++)
    {
        inserted = rand()%100000;
        test_splay_tree.insert(inserted);
    }
    auto start = high_resolution_clock::now();
    for(int i = 0; i<100; i++)
    {
        test_splay_tree.find(rand()%1000);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "1% 100,000 Keys: " << duration.count() << endl;
}

TEST_CASE("10% 100,000 Keys") {
    splay_tree_implementation test_splay_tree;
    int inserted;
    for(int i=0; i<100000; i++)
    {
        inserted = rand()%100000;
        test_splay_tree.insert(inserted);
    }
    auto start = high_resolution_clock::now();
    for(int i = 0; i<100; i++)
    {
        test_splay_tree.find(rand()%10000);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "10% 100,000 Keys: " << duration.count() << endl;
}

TEST_CASE("50% 100,000 Keys") {
    splay_tree_implementation test_splay_tree;
    int inserted;
    for(int i=0; i<100000; i++)
    {
        inserted = rand()%100000;
        test_splay_tree.insert(inserted);
    }
    auto start = high_resolution_clock::now();
    for(int i = 0; i<100; i++)
    {
        test_splay_tree.find(rand()%50000);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "50% 100,000 Keys: " << duration.count() << endl;
}

TEST_CASE("100% 100,000 Keys") {
    splay_tree_implementation test_splay_tree;
    int inserted;
    for(int i=0; i<100000; i++)
    {
        inserted = rand()%100000;
        test_splay_tree.insert(inserted);
    }
    auto start = high_resolution_clock::now();
    for(int i = 0; i<100; i++)
    {
        test_splay_tree.find(rand()%100000);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "100% 100,000 Keys: " << duration.count() << endl;
}

