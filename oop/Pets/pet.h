#pragma once

#include <iostream>

#define PRINT(x) std::cout<< x << std::endl

class Pet {
protected:
    std::string name;
    int age{};

public:
    Pet() : name({}), age(0) {};

    Pet(const std::string &name, int age) : name(name), age(age) {};

    virtual ~Pet() = default;// Added a virtual destructor at the suggestion of GPT as nothing else was resolving memory leak. This works to clear memory leaks since it makes sure cleanup occurs when class objects are deleted

    virtual void play(const std::string &) = 0;

    virtual const std::string as_string() {
        return "{name:" + name + ", age:" + std::to_string(age) + "}";
    };
};