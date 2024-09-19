#include "dog.h"

Dog::Dog(const std::string &name, int age, const std::string &owner,
         Pet **friends, int num_of_friends) : Dog(name, age, owner) {
    if (num_of_friends <= 0) {
        return;
    }

    make_friends(friends, num_of_friends);
}

void Dog::make_friends(Pet *const *friends_to_make, int num_of_friends_to_make) {
    delete[] this->friends; // I added this at the suggestion of GPT, it is supposed to deallocate memory if there are existing friends in the array
    num_of_friends = num_of_friends_to_make + 1;// Originally I removed the + 1 and the code ran. However, when trying to debug memory leak caused by this function, I asked GPT what was causing the program to crash because I tried putting 'delete[] friends;' at the end of this function and broke the program. GPT recommended I put the + 1 back to avoid going out of bounds, and let ~Dog delete the array in dog.h
    this->friends = new Pet *[num_of_friends];
    if (friends_to_make != nullptr) {
        for (int i = 0; i < num_of_friends_to_make; ++i) {
            Dog::friends[i] = friends_to_make[i];
        }
    }
    friends[num_of_friends - 1] = this;// GPT suggested I add -1 to this function instead of removing +1 on line 13, code runs when assigning final element
}

const std::string Dog::as_string() {
    return "dog{name:" + name + ", age:" + std::to_string(age) + "}";
}

void Dog::play(const std::string &toy) {
    if (!toy.empty()) {
        PRINT(as_string() + ": " + toy);
        return;
    }
    PRINT(as_string() + " is playing with a stick found somewhere)");
}

Pet **Dog::getFriends() const {
    return friends;
}

int Dog::getNumOfFriends() const {
    return num_of_friends;
}
