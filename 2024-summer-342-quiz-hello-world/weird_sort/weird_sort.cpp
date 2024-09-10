#include <iostream>
#include "weird_sort.h"

void copy_array(int *data_dest, int *data_src, size_t len) {// I couldn't figure out what was wrong with this function so I asked GPT
    if (len == 0) {
        return;
    }
    memcpy(data_dest, data_src, len * sizeof(int));// Covered in class. There was a problem with the 'memcpy' function. To fix the problem, I made the following change: len * sizeof(int). This change copies the elements of the array instead of the number of bytes
}

void print_array(int *data, size_t len) {
    printf("{");
    for (int i = 0; i < len; i++) {
        printf("%d", data[i]);
        if (i != len - 1) {
            printf(", ");
        } else {
            printf("}\n");
        }
    }
}

void swap(int *data, int i, int j)// Used similar swap function from swap_array, only this version is swapping values in a single array
{
    int temp = data[i];
    data[i] = data[j];
    data[j] = temp;
}

void sort_even_elements(int *data, size_t len, long &num_comparison) {
    if (data == nullptr || len < 2) {
        return;
    }

    for (int i = 0; i < len; i+=2) { // I asked GPT for help with writing this. I went with i+=2 due to its suggestion, and after testing I noticed there were more comparisons when using i++ vs i+=2, meaning i+=2 is more efficient. i+=2 is more efficient because the outer loop is run on only even indexes, rather than every index when it's i++
        for (int j = 0; j < len - 2; j+=2) { // My original test kept failing on cases with 4 elements because I was using j++. When I adjusted this to j+=2, the test was successful
            num_comparison++; // added this to track comparisons, when I would run the program the output showed 0, now the number of comparisons is printed
            if (data[j] > data[j + 2]) {    // this is where comparison happens
                swap(data, j, j + 2);
            }
        }
    }
}

int main() {
    unit_test();
    return 0;
}

void unit_test() {
    for (size_t len = 1; len < 500; len++) {
        int *data = new int[len];
        long num_of_comparison = 0;

        /*
         * Some sample inputs. One case per line.
         *
         * 1
         * 2 1
         * 3 2 1
         * 4 3 2 1
         * 5 4 3 2 1
         * 6 5 4 3 2 1
         *
         * 1
         * 2 1
         * 1 2 3
         * 2 3 4 1
         * 1 4 3 2 5
         * 2 5 4 3 6 1
         */
        for (int j = 0; j < len; ++j) {
            data[j] = (int) (len - j);
        }
        int *data_copy = new int[len];
        copy_array(data_copy, data, len);

        sort_even_elements(data, len, num_of_comparison);

        /*
         * verify the even index number
         */
        bool fail = false;
        int expect = (len % 2 == 0) ? 2 : 1;
        for (int j = 0; j < len; j += 2) {
            if (data[j] != expect) {
                fail = true;
                break;
            }
            expect += 2;
        }
        VERIFY(data, data_copy, len, fail);

        /*
         * verify the odd index number
         */
        fail = false;
        expect = (int) len - 1;
        for (int j = 1; j < len; j += 2) {
            if (data[j] != expect) {
                fail = true;
                break;
            }
            expect -= 2;
        }
        VERIFY(data, data_copy, len, fail);

        //Compared with professor, my code has 62250 comparisons for 499 elements vs 62001 for 500

        printf("%ld\t%ld\n", len, num_of_comparison);

        delete[] data;
        delete[] data_copy;
        data = nullptr;
        data_copy = nullptr;
    }
}

