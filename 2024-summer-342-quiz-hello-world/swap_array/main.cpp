#include "util.hpp"

#define SIZE 5
int main() {
    /*
     * swap statically defined arrays
     */
    int static_array_1[SIZE] = {1, 2, 3, 4, 5};
    int static_array_2[SIZE] = {-1, -2, -3, -4, -5};
    swap(static_array_1, static_array_2, SIZE);
    print_array<int>(static_array_1, SIZE);
    print_array<int>(static_array_2, SIZE);

    /*
     * swap dynamically defined arrays
     */
    int *dynamic_array_1= new int[SIZE]{-3, -2, -1, 9, -10};
    int *dynamic_array_2= new int[SIZE]{1, 2, 3, 4, 5};

    delete[]dynamic_array_1;
    delete[]dynamic_array_2;
}
