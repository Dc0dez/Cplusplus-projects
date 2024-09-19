#include <vector>
#include <iostream>
#include "../swap_values/util.hpp"

using namespace std;

template<typename T>
void swap(T *array1, T *array2, int length) {// implemented demo from class
    for(int i = 0; i < length; i++) {
	    swap(array1+i, array2+i);
    }
}

template<typename T>
void print_array(T *array, int len) {
    for (int i = 0; i < len; i++) {
        cout << "data" << "[" << i << "] = " << array[i] << endl;
    }
}
