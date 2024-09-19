/*
 * DO NOT CHANGE CODE UNLESS SPECIFIED (such as TODOs)
 */

#ifndef ARRAY_LIST
#define ARRAY_LIST

template<class T>
class List {
public:
    // return the capacity of the list
    virtual size_t capacity() const = 0;

    // return the number of elements in the list
    virtual size_t size() const = 0;

    // inserts an element to the beginning
    virtual void push_front(const T &value) = 0;

    // adds an element to the end
    virtual void push_back(const T &value) = 0;

    // removes the last element
    virtual void pop_back() = 0;

    // removes the first element
    virtual void pop_front() = 0;

    // add an element to the end of the list
    virtual void remove(T &val) = 0;

    // merges two sorted lists
    virtual void merge(const List<T> &other) = 0;

    virtual ~List() {}
};

template<class T>
class ArrayList : public List<T> {
private:
    T *data;
    size_t max_capacity;
    size_t num_of_element;

public:
    ArrayList() = delete;   // disable default constructor

    // constructor
    ArrayList(size_t capacity) : max_capacity(capacity), num_of_element(0) {
        data = new T[capacity];
    }

    // copy constructor
    ArrayList(const ArrayList<T> &other_list) : max_capacity(other_list.max_capacity),
                                                num_of_element(other_list.num_of_element) {
        data = new T[max_capacity];
        for (size_t i = 0; i < other_list.num_of_element; i++) {
            data[i] = other_list.data[i];
        }
    }

    // destructor
    virtual ~ArrayList() {
        delete[]data;
    }

    size_t capacity() const override {
        return max_capacity;
    }

    size_t size() const override {
        return num_of_element;
    }

    T &operator[](int index) {
        return data[index];
    }

    bool operator==(const ArrayList<T> &other_list) {
        // not comparing capacity as eventually array list can be made capacity irrelevant using dynamic allocation
        if (num_of_element != other_list.num_of_element) {
            return false;
        }
        for (int i = 0; i < num_of_element; i++) {
            if (data[i] != other_list.data[i]) {
                return false;
            }
        }
        return true;
    }

    void push_front(const T &value) override;

    void push_back(const T &value) override;

    void pop_back() override;

    void pop_front() override;

    void remove(T &val) override;

    void merge(const List<T> &other) override;

private:
};

#include "array_and_list.cpp"

#endif