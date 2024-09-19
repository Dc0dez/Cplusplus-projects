#include "iostream"
#include "node.hpp"
using namespace std;

template<typename T>
class Stack {
public:
    virtual void push(T val) = 0;

    virtual T pop() = 0;

    virtual T peek() = 0;

    virtual ~Stack() = default;
};

template<typename T>
class LinkedListStack : public Stack<T> { // I got help from GPT with writing the code in this .hpp file.
private:
    size_t num_of_elements = 0;
    ListNode<T>* head = nullptr;
public:
    LinkedListStack() { // head = nullptr and num_of_elements = 0 initializes an empty stack.
       head = nullptr;
       num_of_elements = 0;
       // The capacity of the stack is dependent on available memory.
    }

    void push(T val) override {
        auto new_node = new ListNode<T>(val); // Allocates memory for a new node with val[value], initializes next pointer to nullptr.
        new_node->next = head; // Sets the next pointer of the new node to the current head of the stack, links the new node to the stack.
        head = new_node; // Updates head to point to the new node, new node is now the head of the stack.
        ++num_of_elements; // Increments 'num_of_elements' to show the new element in the stack.
    }

    T pop() override {
        if(is_empty()){ // Throws an error if the stack is empty.
            cerr << "Stack is empty" << endl;
            exit(EXIT_FAILURE);
        }

        ListNode<T>* temp = head; // Stores current top node in a temporary pointer.
        T popped_value = head->val; // Gets the value from the top node to be returned.
        head = head->next; // Updates the head to point to the next node in the stack.
        delete temp; // Deallocates memory for old top node.
        --num_of_elements; // Decrements 'num_of_elements' to show the element was removed from the stack.
        return popped_value; // Returns value of the popped node.
    }

    ~LinkedListStack() {
        while (head != nullptr){ // Iterates over each node in the stack, head is the beginning.
            ListNode<T>* temp = head; // Stores current node.
            head = head->next; // Moves head to the next node.
            delete temp; // Deallocates memory for the current node.
        }
    }

    T peek() override {
       return head->val; // Returns the value of the top of the stack without deleting it.
    }

    bool is_empty() {
        return num_of_elements == 0;
    }
};