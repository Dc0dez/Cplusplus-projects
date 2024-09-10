#include <iostream>
#include "test.hpp"

void queue_test() {
    ArrayQueue<int> queue(5);

    for (int i = 0; i < 5; ++i) {
        queue.enqueue(i + 1);
    }

    //I got help from GPT on implementing the first automated test and used it as a template to create the others.

    // array content: [1 2 3 4 5]
    std::vector<int> expected = {1,2,3,4,5};
    std::vector<int> actual = queue.get_all_elements();
    PRINT_TEST(expected == actual, "Enqueue Test", expected, actual);

    queue.dequeue();
    // array content: [_ 2 3 4 5]
    expected = {2,3,4,5};
    actual = queue.get_all_elements();
    PRINT_TEST(expected == actual, "Enqueue Test", expected, actual);

    queue.enqueue(6);
    // array content: [6 2 3 4 5]
    expected = {2,3,4,5,6};
    actual = queue.get_all_elements();
    PRINT_TEST(expected == actual, "Enqueue Test", expected, actual);

    queue.dequeue();
    queue.dequeue();
    expected = {4,5,6};
    actual = queue.get_all_elements();
    PRINT_TEST(expected == actual, "Enqueue Test", expected, actual);

    queue.enqueue(7);
    expected = {4,5,6,7};
    actual = queue.get_all_elements();
    PRINT_TEST(expected == actual, "Enqueue Test", expected, actual);

    queue.enqueue(8);
    expected = {4,5,6,7,8};
    actual = queue.get_all_elements();
    PRINT_TEST(expected == actual, "Enqueue Test", expected, actual);
}