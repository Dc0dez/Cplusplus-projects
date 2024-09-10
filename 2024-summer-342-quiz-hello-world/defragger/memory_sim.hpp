#include <stdexcept>
#include <iostream>
#include <cmath>

class MemorySim {
private:
    const int capacity;
    int number_of_used_byte;
    char *memory_blocks;

public:
    MemorySim(int size) : capacity(size), number_of_used_byte(0) {
        if (size <= 0) {
            throw std::invalid_argument("received negative value");
        }
        memory_blocks = new char[size];
    }

    ~MemorySim() {
        delete[] memory_blocks;
    }

    void defrag();

    void setContent(const std::string &);

    std::string getContent();

    int getCapacity() const {
        return capacity;
    }

    int getNumOfUsedBytes() const {
        return number_of_used_byte;
    }

    void setUsed(int used) {
        MemorySim::number_of_used_byte = used;
    }
};