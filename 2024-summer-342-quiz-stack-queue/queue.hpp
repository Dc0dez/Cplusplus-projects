#include <iostream>
#include <sstream>
using namespace std;
/*
 * In arrays circular, elements flow,
 * Head and tail dance in rhythmic show.
 * Bound by limits, yet never still,
 * Efficiently managing, as slots fill.
 *
 * Overflow whispers, capacity sings,
 * Circular queue, where order springs.
 * Array's dance of structured grace,
 * In memory's embrace, a circular chase.
 *                      - ChatGPT
 */
template<typename T>
class Queue {
public:
    virtual void enqueue(T value) = 0;

    virtual T dequeue() = 0;
};

template<typename T>
class ArrayQueue : public Queue<T> {
private:
    T *data = nullptr;
    size_t capacity = 0;
    size_t num_of_elements = 0;
    size_t front = 0;
    size_t rear = 0;

    // I got help from GPT on implementing this class.
public:
    explicit ArrayQueue(size_t capacity) : capacity(capacity) {
        data = new T[capacity]; // Allocates array type T with specified capacity.
    }

    void enqueue(T value) override {
        if (num_of_elements == capacity) { // Checks if the queue is full. Throws an error if true.
            throw overflow_error("Queue is full");
        }
        data[rear] = value; // Sets value to the last index in the queue.
        rear = (rear + 1) % capacity; // Allows for 'rear' to wrap around to the beginning of the array ('data') when it reaches the end (capacity - 1).
        num_of_elements++; // Increments the number of elements.
    }

    T dequeue() override {
        if (num_of_elements == 0) { // Checks if the queue is empty. Throws an error if true.
            throw underflow_error("Queue is empty");
        }

        T value = data[front]; // Sets the value to the front of the queue.
        front = (front + 1) % capacity; // Allows for 'front' to wrap around to the beginning of the array ('data') when it reaches the end (capacity - 1).
        num_of_elements --; // Decrements the number of elements, removing the first value.
        return value; // Returns the new front value.
    }

    void print() {
        /*
         *  How to test this?
         */

        if (num_of_elements == 0) { // Prints a message if the queue is empty.
            cout << "Queue is empty" << endl;
            return;
        }
        size_t curr = front; // Sets the current value to the front of the queue.
        for (size_t i = 0; i < num_of_elements; i++) { // Loops through the number of elements.
            cout << data[curr] << endl; // Prints the elements in the array queue.
            curr = (curr + 1) % capacity;// Ensures that 'curr' moves to the next element in the circular queue. Starts at 'front' and moves through the elements until it reaches the end.
        }
    }

    // I Created this  helper method for the tests in queue_test, suggested by GPT.
    std::vector<T> get_all_elements() const { // Creates a vector that contains all the elements in the array queue.
        std::vector<T> elements; // Initializes a vector for the elements.
        size_t curr = front; // Sets current to the front value.
        for (size_t i = 0; i < num_of_elements; i++) { // Loops through the elements in the array.
            elements.push_back(data[curr]); // Pushes all the elements into the current array.
            curr = (curr + 1) % capacity; // Functions similarly to the code in void print.
        }
        return elements; // Returns the elements in the queue.
    }

    bool is_empty() {
        return num_of_elements == 0;
    }

    ~ArrayQueue() {
        delete[] data; // Deallocates memory from data
        data = nullptr; // Sets data to null to prevent hanging pointer.
    }
};