#include <iostream>
#include <vector>
#include <iterator>
#include "node.hpp"
#include "stack.hpp"
#include "queue.hpp"

void queue_test();

void stack_test();

template<typename T>
void print_test(bool passed, const std::string &test_name,
                T expect, T actual, int line_number) {
    if (passed) {
        std::cout << test_name << " (line " << line_number << "): PASSED." << std::endl;
        return;
    }
    std::cout << test_name << " (line " << line_number << "): FAILED. Expected: "
              << expect << ". Actual: " << actual << std::endl;
}

template<typename T>
std::string vector_2_string(const std::vector<T> &vec, const std::string &delimiter = ", ") {
    if (vec.empty()) return "";

    std::ostringstream oss;
    std::copy(vec.begin(), vec.end() - 1, std::ostream_iterator<T>(oss, delimiter.c_str()));
    oss << vec.back();
    return oss.str();
}

// The difference between the first print test and the second print test is that the first print test stores single values and the second print test stores multiple values in a vector.
template<typename T>
void print_test(bool passed, const std::string &test_name,
                std::vector<T> expect, std::vector<T> actual, int line_number) {
    if (passed) {
        std::cout << test_name << " (line " << line_number << "): PASSED." << std::endl;
        return;
    }
    std::cout << test_name << " (line " << line_number << "): FAILED. Expected: "
              << vector_2_string<T>(expect) << ". Actual: " << vector_2_string<T>(actual) << std::endl;
}

#define PRINT_TEST(passed, test_name, expect, actual) print_test(passed, test_name, expect, actual, __LINE__)