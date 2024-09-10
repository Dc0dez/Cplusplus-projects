#include "problem_2.h"

/*
 * OK to add function in this file
 */
void Sorter::my_swap(int &s1, int &s2) {
    int temp = s1;
    s1 = s2;
    s2 = temp;
}
void Sorter::bubble_sort(int *data, int length) { // borrowed code from in-class example and a previous assignment that I got help with in the QSC
    if(data == nullptr || length <= 1) {
        return;
    }

    bool sortArray;
    for (int i = 0; i < length - 1; i++) {
        sortArray = false;
        for (int j = 0; j < length - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                my_swap(data[j], data[j + 1]);
                sortArray = true;
            }
        }
        if(!sortArray) {
            break;
        }
    }
}