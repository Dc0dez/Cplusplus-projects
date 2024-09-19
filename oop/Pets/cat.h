#include <iostream>
#include "pet.h"

class Cat : public Pet {

public:
    static int num_of_times_copy_constructor_called;

    Cat(const std::string &name, int age);

    Cat(const Cat &other_cat) : Cat(other_cat.name, other_cat.age) {
        num_of_times_copy_constructor_called++;
    }

    std::vector<Cat> operator*(int num);

    void play(const std::string &) override;

    const std::string as_string() override;
};