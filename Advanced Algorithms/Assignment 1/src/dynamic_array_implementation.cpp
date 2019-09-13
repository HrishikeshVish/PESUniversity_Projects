#include "../include/dynamic_array.hpp"

using namespace std;

//Given just for reference. Only the class name and function names should match.
class dynamic_array_implementation : public dynamic_array
{
private:
    int size;
    int capacity;
    int *arr;
    double increase_factor;
    double decrease_factor;
    inline double get_increase_factor(){return increase_factor;};
    inline double get_decrease_factor(){return decrease_factor;};

public:
    dynamic_array_implementation();
    int get_size();
    int get_capacity();
    void set_increase_factor_table_size(double);
    void set_load_factor_reduction(double);
    void append(int);
    void pop();
    int get(int);
    ~dynamic_array_implementation();
};

dynamic_array_implementation::dynamic_array_implementation()
{
    size = 0;
    capacity = 0;
    increase_factor = 2;
    decrease_factor = 0.25;
    arr = new int[0];
}

int dynamic_array_implementation::get_size()
{
    return size;
}

int dynamic_array_implementation::get_capacity()
{
    return capacity;
}

void dynamic_array_implementation::set_increase_factor_table_size(double increase_factor)
{
    this->increase_factor = increase_factor;
    return;
}

void dynamic_array_implementation::set_load_factor_reduction(double decrease_factor)
{
    this->decrease_factor = decrease_factor;
    return;
}

void dynamic_array_implementation::append(int element)
{

	
    if (size == capacity) {
		if(capacity == 0) capacity ++;

    	else capacity = (int)(capacity *get_increase_factor());
        int * temp = new int [capacity];
        int i;
        for (i = 0; i < size; i++)
        {
            temp [i] = arr [i];
        }
        delete[] arr;
        arr = temp;
    }

    arr[size] = element;
    size++;    return;
}

void dynamic_array_implementation::pop()
{
    if (size == 0){capacity = 0; return;}
    size--;;
    if (size == 0) {
     	delete[] arr;
		arr = new int[0];
        capacity = 0;
        return;}
    double minval = capacity*get_decrease_factor();
    if (size <= minval) {
    	capacity = (int)minval*get_increase_factor();
        int * temp = new int [capacity];
        int i;
        for (i = 0; i < size; i++)
        {
            temp [i] = arr [i];
        }
        delete[] arr;
        arr = temp;
    }

    return;
}

int dynamic_array_implementation::get(int index)
{
    if(index >= 0 && index < size){
	
    return arr[index];
    
	}
    else{throw "Array Index Out of Bounds";}
}

dynamic_array_implementation::~dynamic_array_implementation()
{
    if (capacity > 0)
    {
        delete[] arr;
    }
}
