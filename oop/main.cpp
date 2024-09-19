#include <iostream>
#include <vector>
#include "Pets/dog.h"
#include "Pets/cat.h"

void dog_make_friends();

void cat_copy_cat();

int main() {
    dog_make_friends();

    cat_copy_cat();

    return 0;
}

void cat_copy_cat() {
    Cat chloe("Chloe", 3);

    std::vector<Cat> copy_cats = chloe * 5; // This line uses the operator function std::vector<Cat> Cat::operator*(int num_of_copies) to create 5 cat {name:Chloe, age:3} objects in the vector<Cat> copy_cats

    for (Cat cat: copy_cats) {
        PRINT(cat.as_string());
    }

    PRINT("copy constructor is called " +
                  std::to_string(Cat::num_of_times_copy_constructor_called) + " times.");
}

void dog_make_friends() {
    Dog sam("Sam", 5, "Stella");
    Dog max("Max", 2, "Kyle");
    Cat *coco = new Cat("coco", 7);
    Pet *roger = new Dog("Roger", 5, "Peng");

    Pet *friends_list[4] = {&sam, &max, roger, coco};
    Pet *emily = new Dog("Emily", 3, "Alan",
                         friends_list,
                         sizeof(friends_list) / sizeof(Pet *));

    /*
     * Dog Emily playing with friends
     */
    Dog *p_emily_as_a_dog = (Dog *) emily;
    Pet **emily_friends = p_emily_as_a_dog->getFriends();
    int num_of_friends = p_emily_as_a_dog->getNumOfFriends();
    for (int i = 0; i < num_of_friends; ++i) {
        emily_friends[i]->play("May the 4th be woof you!");
    }

    delete coco;
    coco = nullptr;
    delete roger;
    roger = nullptr;
    delete emily;
    emily = nullptr;
}
