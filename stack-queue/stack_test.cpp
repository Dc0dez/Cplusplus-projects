#include "test.hpp"

void stack_test() {
    LinkedListStack<int> stack;
    for (int i = 0; i < 5; ++i) {
        stack.push(i * 100);
    }
// I ran this by GPT for clarification. I wanted to use i > 0, but GPT recommended i >= 0 to ensure the loop iterates through all the elements.
    for (int i = 4; i >= 0; --i) { // In stack test, 5 values (0, 100, 200, 300, and 400) are pushed onto the stack. When running the debugger, the expected value is 0 but the actual value is 400. Since these values do not match, the test fails on line 13. Because the values are popping off of the stack in this loop starting at int 400, the loop had to be adjusted to decrement starting from the 4th element until the loop reaches the 1st element, and the final value is popped off the stack.
        int actual = stack.pop();
        int expect = i * 100;// To ensure the value matches, 'i' must be multiplied by 100.
        if (expect != actual) {
            PRINT_TEST(false, "stack_test", expect, actual);
            return;
        }
    }
}