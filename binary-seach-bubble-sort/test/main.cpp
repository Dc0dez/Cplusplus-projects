#include "gtest/gtest.h"

/*
 * Do not make any changes. How about a joke instead:
 * std::cout << "Why did the programmer quit his job?\n";
   std::cout << "Because he didn't get arrays. :)" << std::endl;
 */

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS(); // It's fun though to look into this function and see what it does.
}