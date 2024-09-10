#include <vector>
#include "cat.h"

int Cat::num_of_times_copy_constructor_called = 0;

void Cat::play(const std::string &words) {
    PRINT("cat(" + name + ", " + std::to_string(age) + ") is hyper after eating catnip");
}

Cat::Cat(const std::string &name, int age) : Pet(name, age) {}

const std::string Cat::as_string() {
    return "cat{name:" + name + ", age:" + std::to_string(age) + "}";
}

std::vector<Cat> Cat::operator*(int num_of_copies) {
    std::vector<Cat> copy_cats;
    copy_cats.reserve(num_of_copies);
    for (int i = 0; i < num_of_copies; ++i) {
        // I Used the following resource: https://www.geeksforgeeks.org/push_back-vs-emplace_back-in-cpp-stl-vectors/ and asked GPT. The reason the number of times the constructor is called drops from 10 to 5 is because emplace_back eliminates the need to create temporary Cat objects and copy them into the vector since it creates the Cat objects directly in the vector, resulting in only 5 constructor calls. push_back requires 5 constructor calls to create temporary cat objects and another 5 constructor calls to copy the objects into the vector, resulting in 10 constructor calls
        copy_cats.emplace_back(name, age);
    }
    return copy_cats;
}