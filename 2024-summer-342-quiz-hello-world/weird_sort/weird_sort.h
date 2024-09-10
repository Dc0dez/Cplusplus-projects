#pragma once
#include <cstdio>
#include <string.h>

void print_array(int *data, size_t len);

#define VERIFY(data, data_copy, len, fail)          \
    if (fail) {                                     \
        printf("Case with %lu elements failed\n", (len)); \
        printf("Input: ");                          \
        print_array((data_copy), (len));            \
        printf("Output: ");                         \
        print_array((data), (len));                 \
        break;                                      \
    }

void unit_test();
