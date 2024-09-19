#include <iostream>

template<typename T>
void assert_equals(const T &expect, const T &actual, const std::string &case_id) {
    if (expect != actual) {
        std::cout << "Failed test " << case_id << std::endl;
        std::cout << "  Expect: '" << expect << "'" << std::endl;
        std::cout << "  Actual: '" << actual << "'" << std::endl;
    }
}
