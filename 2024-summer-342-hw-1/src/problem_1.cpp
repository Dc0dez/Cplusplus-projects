#include "problem_1.h"

/*
 * Do not modify the function signature (name, parameters, return type)
 */
int Searcher::binary_search(const int *data, int length, int target) { // to write this implementation, I followed along with tutorial at: https://www.youtube.com/watch?v=vohuRrwbTT4&list=PLt7h-F1RpA6F7Blgqv4Ogo-mkuGjtlIdn&index=6&ab_channel=ReelLearning
    if(data == nullptr || length == 0) {
        return -1;
    }

    int low = 0;
    int high = length - 1;
    int mid;

    while (low <= high) {
        mid = low + (high - low) / 2;// adjusted this based on geeksforgeeks example: https://www.geeksforgeeks.org/binary-search/ and suggestion by GPT. Writing the code this way prevents overflow

        if (target == data[mid]) {
            return mid;
        } else if (target > data[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
    // Why does this even compile when the function is supposed to return an int but it's not returning any return value?
}
