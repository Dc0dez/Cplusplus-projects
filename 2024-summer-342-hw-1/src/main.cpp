#include <cstdio>
#include "problem_1.h"
#include "problem_2.h"

/*
 * This file does run through memory check at submission.
 * Changes in this file will be ignored for grading
 * However, if there's memory leak from this file, or it doesn't compile, there will be points deduction
 * Rule of thumb is that your submitted code should compile to be able to get graded.
 */

int main(int argc, char **argv) {
    /*
     * code here are for demo purpose only.
     * the questions in the comments are for study only. you won't be graded for these.
     */
    printf("hello CSS342\n");
    std::cout << "Another way to say hello!" << std::endl;  // what does "std::endl" do? GPT it if not sure.
    std::cout
            << "A third way to say hello!\n";  // how does this compare to the line right above? What's the difference?

    int *data = new int[4]{1, 2, 3, 4};
    int result = Searcher::binary_search(data, 4, 2);   // what happens 40 instead of 4 is passed in here?
    printf("search result %d\n", result);
    delete[] data;
    data = nullptr;

    data = new int[4]{3, 1, 2, -2};
    Sorter::bubble_sort(data, 4);
    for (int i = 0; i < 4; i++) {
        printf("%d\n", data[i]);
    }
    delete[] data;
    data = nullptr;

    return 0;
}