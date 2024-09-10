#include "move_items.hpp"
#include "reverse_stack.hpp"
#include "util.hpp"
#include <cassert>

int main() {
    test_move_items();
    test_reverse_stack();
}

/*
 * DO NOT CHANGE THIS FUNCTION
 */
void test_move_items() {
    std::vector<std::pair<int, std::vector<std::string>>> test_cases = {
            {3,
                    {
                            "Move item 1 from plate S to plate D",
                            "Move item 2 from plate S to plate X",
                            "Move item 1 from plate D to plate X",
                            "Move item 3 from plate S to plate D",
                            "Move item 1 from plate X to plate S",
                            "Move item 2 from plate X to plate D",
                            "Move item 1 from plate S to plate D"
                    }
            },
            {5,
                    {
                            "Move item 1 from plate S to plate D",
                            "Move item 2 from plate S to plate X",
                            "Move item 1 from plate D to plate X",
                            "Move item 3 from plate S to plate D",
                            "Move item 1 from plate X to plate S",
                            "Move item 2 from plate X to plate D",
                            "Move item 1 from plate S to plate D",
                            "Move item 4 from plate S to plate X",
                            "Move item 1 from plate D to plate X",
                            "Move item 2 from plate D to plate S",
                            "Move item 1 from plate X to plate S",
                            "Move item 3 from plate D to plate X",
                            "Move item 1 from plate S to plate D",
                            "Move item 2 from plate S to plate X",
                            "Move item 1 from plate D to plate X",
                            "Move item 5 from plate S to plate D",
                            "Move item 1 from plate X to plate S",
                            "Move item 2 from plate X to plate D",
                            "Move item 1 from plate S to plate D",
                            "Move item 3 from plate X to plate S",
                            "Move item 1 from plate D to plate X",
                            "Move item 2 from plate D to plate S",
                            "Move item 1 from plate X to plate S",
                            "Move item 4 from plate X to plate D",
                            "Move item 1 from plate S to plate D",
                            "Move item 2 from plate S to plate X",
                            "Move item 1 from plate D to plate X",
                            "Move item 3 from plate S to plate D",
                            "Move item 1 from plate X to plate S",
                            "Move item 2 from plate X to plate D",
                            "Move item 1 from plate S to plate D"
                    }
            }
    };

    for (auto &test_case: test_cases) {
        std::vector<std::string> actual;

        move_items(test_case.first, 'S', 'D', actual);
        auto expect = test_case.second;
        std::cout << "test_move_items: case of size " <<
                  std::to_string(test_case.first) << ((expect == actual) ? " PASSED" : " FAILED")
                  << std::endl;
    }
};

// Assert function to compare actual and expected values
void assert_equal(int actual, int expected) {
    assert(actual == expected);
}

void test_reverse_stack() {
    // Creates stack my_stack
    std::stack<int> my_stack;
    // Pushes elements onto my_stack
    for (int i = 0; i < 10; ++i) {
        my_stack.push(i * 10);
    }

    // at this point, stack should have:
    //  TOP [90, 80, ... 20, 10, 0] BOTTOM

    // Calls reverse_stack to reverse the elements in my_stack
    reverse_stack(my_stack);

    // I got help from GPT with implementing the expected stack
    // Creates stack expected_stack
    std::stack<int>expected_stack;
    // Pushes elements onto expected_stack: TOP [0, 10, 20, ... 80, 90] BOTTOM
    for (int i = 9; i >= 0; --i) {
        expected_stack.push(i * 10);
    }
    // at this point, stack should have:
    //  TOP [0, 10, 20, ... 80, 90] BOTTOM

    // Loops through elements of expected stack if it is not empty
    while (!expected_stack.empty()) {
        // Checks that my_stack is not empty
        assert(!my_stack.empty());
        // Sets actual equal to the top element of my_stack
        int actual = my_stack.top();
        // Sets expected equal to the top element of expected_stack
        int expected = expected_stack.top();
        // Checks that the actual value is equal to the expected value
        assert_equal(actual, expected);
        // Pops the top element off of my_stack
        my_stack.pop();
        // Pops the top element off of expected_stack
        expected_stack.pop();
    }
    // Checks to ensure my_stack is empty once comparison is finished
    assert(my_stack.empty());
    // Checks to ensure expected_stack is empty once comparison is finished
    assert(expected_stack.empty());
};
