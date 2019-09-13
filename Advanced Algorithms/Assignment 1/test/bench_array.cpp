#include "../src/dynamic_array_implementation.cpp"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <chrono> 

using namespace std::chrono;

TEST_CASE("10,000 Inserts") {
    dynamic_array_implementation test_dynamic_array;
    int inserted;
    auto start = high_resolution_clock::now(); 
    for(int i = 0; i<10000; i++)
    {
        inserted = rand()%100;
        test_dynamic_array.append(inserted);
    }
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start);
    CHECK(test_dynamic_array.get_size() == 10000); 
    cout << "10,000 Inserts: " << duration.count() << endl;
}

TEST_CASE("100,000 Inserts") {
    dynamic_array_implementation test_dynamic_array;
    int inserted;
    auto start = high_resolution_clock::now(); 
    for(int i = 0; i<100000; i++)
    {
        inserted = rand()%100;
        test_dynamic_array.append(inserted);
    }
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start);
    CHECK(test_dynamic_array.get_size() == 100000); 
    cout << "100,000 Inserts: " << duration.count() << endl;
}

TEST_CASE("10,000 Deletes") {
    dynamic_array_implementation test_dynamic_array;
    int inserted;
    for(int i = 0; i<10000; i++)
    {
        inserted = rand()%100;
        test_dynamic_array.append(inserted);
    }
    CHECK(test_dynamic_array.get_size() == 10000); 
    auto start = high_resolution_clock::now(); 
    for(int i = 0; i<10000; i++)
    {
        inserted = rand()%100;
        test_dynamic_array.pop();
    }
    auto stop = high_resolution_clock::now(); 
    CHECK(test_dynamic_array.get_size() == 0); 
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "10,000 Deletes: " << duration.count() << endl;
}

TEST_CASE("100,000 Deletes") {
    dynamic_array_implementation test_dynamic_array;
    int inserted;
    for(int i = 0; i<100000; i++)
    {
        inserted = rand()%100;
        test_dynamic_array.append(inserted);
    }
    CHECK(test_dynamic_array.get_size() == 100000); 
    auto start = high_resolution_clock::now(); 
    for(int i = 0; i<100000; i++)
    {
        inserted = rand()%100;
        test_dynamic_array.pop();
    }
    auto stop = high_resolution_clock::now(); 
    CHECK(test_dynamic_array.get_size() == 0); 
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "100,000 Deletes: " << duration.count() << endl;
}

TEST_CASE("10 Inserts/Deletes 1000 Epochs") {
    dynamic_array_implementation test_dynamic_array;
    int inserted;
    auto start = high_resolution_clock::now(); 
    for(int i = 0; i<1000; i++)
    {
        for(int j = 0; j<10; j++)
        {
            inserted = rand()%100;
            test_dynamic_array.append(inserted);
        }
        CHECK(test_dynamic_array.get_size() == 10);
        for(int k = 0; k<10; k++)
        {
            test_dynamic_array.pop();
        }
        CHECK(test_dynamic_array.get_size() == 0);
        
    }
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "10 Inserts/Deletes 1000 Epochs: " << duration.count() << endl;
}

TEST_CASE("100 Inserts/Deletes 1000 Epochs") {
    dynamic_array_implementation test_dynamic_array;
    int inserted;
    auto start = high_resolution_clock::now(); 
    for(int i = 0; i<1000; i++)
    {
        for(int j = 0; j<100; j++)
        {
            inserted = rand()%100;
            test_dynamic_array.append(inserted);
        }
        CHECK(test_dynamic_array.get_size() == 100);
        for(int k = 0; k<100; k++)
        {
            test_dynamic_array.pop();
        }
        CHECK(test_dynamic_array.get_size() == 0);
        
    }
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "100 Inserts/Deletes 1000 Epochs: " << duration.count() << endl;
}

TEST_CASE("10,000 Inserts") {
    dynamic_array_implementation test_dynamic_array;
    test_dynamic_array.set_increase_factor_table_size(2);
    test_dynamic_array.set_load_factor_reduction(0.125);
    int inserted;
    auto start = high_resolution_clock::now(); 
    for(int i = 0; i<10000; i++)
    {
        inserted = rand()%100;
        test_dynamic_array.append(inserted);
    }
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start);
    CHECK(test_dynamic_array.get_size() == 10000); 
    cout << "10,000 Inserts: " << duration.count() << endl;
}

TEST_CASE("100,000 Inserts") {
    dynamic_array_implementation test_dynamic_array;
    test_dynamic_array.set_increase_factor_table_size(2);
    test_dynamic_array.set_load_factor_reduction(0.125);
    int inserted;
    auto start = high_resolution_clock::now(); 
    for(int i = 0; i<100000; i++)
    {
        inserted = rand()%100;
        test_dynamic_array.append(inserted);
    }
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start);
    CHECK(test_dynamic_array.get_size() == 100000); 
    cout << "100,000 Inserts: " << duration.count() << endl;
}

TEST_CASE("10,000 Deletes") {
    dynamic_array_implementation test_dynamic_array;
    test_dynamic_array.set_increase_factor_table_size(2);
    test_dynamic_array.set_load_factor_reduction(0.125);
    int inserted;
    for(int i = 0; i<10000; i++)
    {
        inserted = rand()%100;
        test_dynamic_array.append(inserted);
    }
    CHECK(test_dynamic_array.get_size() == 10000); 
    auto start = high_resolution_clock::now(); 
    for(int i = 0; i<10000; i++)
    {
        inserted = rand()%100;
        test_dynamic_array.pop();
    }
    auto stop = high_resolution_clock::now(); 
    CHECK(test_dynamic_array.get_size() == 0); 
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "10,000 Deletes: " << duration.count() << endl;
}

TEST_CASE("100,000 Deletes") {
    dynamic_array_implementation test_dynamic_array;
    test_dynamic_array.set_increase_factor_table_size(2);
    test_dynamic_array.set_load_factor_reduction(0.125);
    int inserted;
    for(int i = 0; i<100000; i++)
    {
        inserted = rand()%100;
        test_dynamic_array.append(inserted);
    }
    CHECK(test_dynamic_array.get_size() == 100000); 
    auto start = high_resolution_clock::now(); 
    for(int i = 0; i<100000; i++)
    {
        inserted = rand()%100;
        test_dynamic_array.pop();
    }
    auto stop = high_resolution_clock::now(); 
    CHECK(test_dynamic_array.get_size() == 0); 
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "100,000 Deletes: " << duration.count() << endl;
}

TEST_CASE("10 Inserts/Deletes 1000 Epochs") {
    dynamic_array_implementation test_dynamic_array;
    test_dynamic_array.set_increase_factor_table_size(2);
    test_dynamic_array.set_load_factor_reduction(0.125);
    int inserted;
    auto start = high_resolution_clock::now(); 
    for(int i = 0; i<1000; i++)
    {
        for(int j = 0; j<10; j++)
        {
            inserted = rand()%100;
            test_dynamic_array.append(inserted);
        }
        CHECK(test_dynamic_array.get_size() == 10);
        for(int k = 0; k<10; k++)
        {
            test_dynamic_array.pop();
        }
        CHECK(test_dynamic_array.get_size() == 0);
        
    }
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "10 Inserts/Deletes 1000 Epochs: " << duration.count() << endl;
}

TEST_CASE("100 Inserts/Deletes 1000 Epochs") {
    dynamic_array_implementation test_dynamic_array;
    test_dynamic_array.set_increase_factor_table_size(2);
    test_dynamic_array.set_load_factor_reduction(0.125);
    int inserted;
    auto start = high_resolution_clock::now(); 
    for(int i = 0; i<1000; i++)
    {
        for(int j = 0; j<100; j++)
        {
            inserted = rand()%100;
            test_dynamic_array.append(inserted);
        }
        CHECK(test_dynamic_array.get_size() == 100);
        for(int k = 0; k<100; k++)
        {
            test_dynamic_array.pop();
        }
        CHECK(test_dynamic_array.get_size() == 0);
        
    }
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "100 Inserts/Deletes 1000 Epochs: " << duration.count() << endl;
}



