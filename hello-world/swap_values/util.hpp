#include <vector>
#include <iostream>

void swap(int &a, int &b);

template<typename T>
void swap(T *a, T *b){
    T temp = *a;
    *a = *b;
    *b = temp;
}
