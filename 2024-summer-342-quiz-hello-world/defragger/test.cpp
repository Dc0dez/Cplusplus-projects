#include <vector>
#include "memory_sim.hpp"
#include "test.hpp"


void simple_test();

void fancy_test();

int main() {
    simple_test();
    fancy_test();
}

#define capacity 100

void simple_test() {
    MemorySim sim(capacity);
    std::string input = ".a.b....c. d e f  ";
    std::string expect = "abcdef";
    sim.setContent(input);

    sim.defrag();
    std::string actual = sim.getContent();

    assert_equals<int>(sim.getCapacity(), capacity, __func__);
    assert_equals<int>(sim.getNumOfUsedBytes(), (int) expect.length(), __func__);
    assert_equals<std::string>(expect, actual, __func__);
}

/*
 * Do not change this test other than the TODO line
 */
void fancy_test() {
    std::vector<std::string> inputs{
            ".a.b....c. d e f  ",
            "...",
            "   ",
            "abc",
            "a.b.c.d"
            ".a..b...c....d.....xyz."
    };
    std::vector<std::string> expect{
            "abcdef",
            "",
            "",
            "abc",
            "abcd"
            "abcdxyz"
    };

    assert_equals(inputs.size(), expect.size(), __func__);

    for (int i = 0; i < inputs.size(); i++) {
        MemorySim sim(capacity);
        sim.setContent(inputs[i]);
        sim.defrag();

        std::string actual = sim.getContent();
        std::string case_id = __func__ + std::string(": case ") + std::to_string(i);

        assert_equals<int>(sim.getCapacity(), capacity, case_id);
        assert_equals<int>(sim.getNumOfUsedBytes(), (int) expect[i].length(), case_id);
        assert_equals<std::string>(expect[i], actual, case_id);

        std::cout << std::endl;
    }
}