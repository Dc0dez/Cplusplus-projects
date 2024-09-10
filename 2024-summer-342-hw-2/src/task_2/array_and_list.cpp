/*
 * DO NOT CHANGE CODE UNLESS SPECIFIED (such as TODOs)
 */
#include "array_and_list.h"

template<class T>// I got help from GPT writing most of these methods except for void ArrayList<T>::pop_back() {.
void ArrayList<T>::push_front(const T &value) {
    if (num_of_element == max_capacity) {// Checks that the array list has space available, returns if true.
        return;
    }

    for (size_t i = num_of_element; i > 0; --i) {// Loops through the array list starting at the end, shifts elements to the right and makes room at the front of the array list.
        data[i] = data[i - 1];
    }

    data[0] = value;// Places the value at data[0], which is the front of the array list.

    ++num_of_element;// Increases the number of elements.
}

template<class T>
void ArrayList<T>::push_back(const T &value) {
    if (num_of_element == max_capacity) {// Checks that the array list has space available, returns if true.
        return;
    }

    data[num_of_element] = value;// Places the value at [num_of_element], which is the end of the array list.

    ++num_of_element;// Increases the number of elements
}
template<class T>
void ArrayList<T>::pop_back() {
    if (num_of_element == 0) {// Checks if the array list is empty, returns if true.
        return;
    }

    --num_of_element;// Reduces number of elements.
}

template<class T>
void ArrayList<T>::pop_front() {
    if (num_of_element == 0) {// Checks if the array list is empty, returns if true.
        return;
    }

    for (size_t i = 0; i < num_of_element - 1; ++i) {// Loops through the array list starting at the beginning. Removes the first element by shifting the elements to the left. Accomplished by iterating through to the second to last element in the array list.
        data[i] = data[i + 1];
    }

    --num_of_element;// Reduces the number of elements.
}

template<class T>
void ArrayList<T>::remove(T &val) {
    size_t new_size = 0;// Keeps track of the amount of variables != to val.

    for (size_t i = 0; i < num_of_element; ++i) {// Loops through the array list starting at the beginning. Moves elements that are not equal to 'val' into new_size and increments new_size.
        if (data[i] != val) {
            data[new_size++] = data[i];
        }
    }

    num_of_element = new_size;// Sets num_of_elements to the new size of the array list after removing the elements.
}

/*
 * merge in ascending order
 */
template<class T>
    void ArrayList<T>::merge(const List<T> &other_list) {

    auto other_array = (ArrayList<T>&)(other_list);// Type casts other_list to ArrayList<t>& to access the data in the array.

    size_t other_list_size = other_list.size(); // Gets the size of other_list.
    size_t combined_size = num_of_element + other_list_size;// Combines the original array list and the new array list.

    ArrayList<T> temp(combined_size); // Creates a temp array list to store the combined elements.

    size_t i = 0, j = 0;// Creates indices for iterating through each array list.

    while(i < num_of_element && j < other_list_size) { // Adds elements from both lists to the temp array list in sorted order.
        if(data[i] < other_array.data[j]) {
            temp.push_back(data[i]);
            ++i;
        }else {
            temp.push_back(other_array.data[j]);
            ++j;
        }
    }

    while(i < num_of_element) { // Copies any remaining elements from num_of_elements into the array list.
        temp.push_back(data[i]);
        ++i;
    }

    while (j < other_list_size) {// Copies any remaining elements from other_list_size into the array list.
        temp.push_back(other_array.data[j]);
        ++j;
    }

    delete[] data;// Deletes the old array list.
    data = new T[combined_size];// Allocates memory for the new array list.

    for (size_t k = 0; k < combined_size; ++k) { // Copies the sorted elements from the temp array into the new array list.
    data[k] = temp.data[k];
    }

    max_capacity = combined_size;// Sets the max capacity to the size of the new array list.
    num_of_element = combined_size;// // Sets the num_of_elements to the size of the new array list.
}