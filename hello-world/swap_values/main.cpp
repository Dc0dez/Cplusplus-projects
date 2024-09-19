#include "util.hpp"

int main(){
    int x = 5, y = 10;
    std::cout << "Before swap: x = " << x << ", y = " << y << "\n";
    swap(x, y); // the reference swap function from util.cpp is being called
    std::cout << "After swap: x = " << x << ", y = " << y << "\n";

    float a = 1.5, b = 2.5;
    std::cout << "Before swap: a = " << a << ", b = " << b << "\n";
    swap(&a, &b); // the templatized pointer swap function from util.hpp is being called
    std::cout << "After swap: a = " << a << ", b = " << b << "\n";
}
