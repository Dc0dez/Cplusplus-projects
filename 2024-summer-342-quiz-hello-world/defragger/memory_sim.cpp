#include "memory_sim.hpp"

void MemorySim::defrag() {// I was not sure what to do here, I asked GPT for help writing the code. Implemented method moves all non-dot chars to the beginning of the array in the correct order. Once all non-dot chars are moved to the front, the dots are filled in at the end of the array
    std::cout << "Defragging '" << std::string(memory_blocks) << "'" << std::endl;

    int j = 0;
    for (int i = 0; i < capacity; ++i){
        if (memory_blocks[i] != '.'){
            memory_blocks[j++] = memory_blocks[i];
        }
    }

    while (j < capacity){
        memory_blocks[j++] = '.';
    }
}

void MemorySim::setContent(const std::string &content) {
    size_t length = content.length();
    if (length == 0) {
        printf("no data to set");
        return;
    }
    int num_of_char_to_copy = std::fmin(capacity, content.length());// Asked GPT what fmin does. My understanding is that this function ensures 'num_of_char_to_copy' is being set to the smallest value between 'capacity' and 'content.length()'. This prevents the possibility of buffer overflow
    for (int i = 0; i < num_of_char_to_copy; ++i) {
        memory_blocks[i] = (content[i] == ' ') ? '.' : content[i];
        if (memory_blocks[i] != '.') {
            number_of_used_byte++;
        }
    }
    if (content.length() > capacity) {
        printf("WARNING: content was clipped due to memory size limitation");
    }
}

std::string MemorySim::getContent() {
    char *ret = new char[number_of_used_byte];
    for (int i = 0; i < number_of_used_byte; ++i) {
        ret[i] = memory_blocks[i];
    }
    return std::string(ret);
}
