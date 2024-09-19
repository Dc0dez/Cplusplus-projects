#include "util.hpp"

// I used lecture code as an example and got help from GPT resolving bugs
template<typename  T>
void insert_to_bottom(T val, std::stack<T> &stack){
    // If the stack is empty, push 'val' onto the stack
    if (stack.empty()) {
        stack.push(val);
        return;
    }
    // Assigns 'top' to the top element of the stack
    T top = stack.top();
    // Pops the top element off the stack
    stack.pop();
    //  Recursively calls 'insert_to_bottom' and places 'val' at the bottom of the stack
    insert_to_bottom(val, stack);
    // Pushes 'top' element back onto the stack
    stack.push(top);
}

template<typename T>
void reverse_stack(std::stack<T> &stack) {
    // If stack is not empty, reverse it
    if(!stack.empty()) {
        // Assigns 'top' to the top element of the stack
        T top = stack.top();
        // Pops top element off the stack
        stack.pop();
        // Recursively calls 'reverse_stack' on the remaining stack
        reverse_stack(stack);
        // Calls 'insert_to_bottom' and places 'top' element at the bottom of the reversed stack
        insert_to_bottom(top, stack);
    }
}
