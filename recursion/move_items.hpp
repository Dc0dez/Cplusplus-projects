#include "util.hpp"
#include <vector>

// I got help from GPT implementing code that updates the vector and used code from class lecture to write the helper method
#define MOVE_DISK(item, from, to, result) result.push_back("Move item " + std::to_string(item) + " from plate " + from + " to plate " + to)

// Helper method
void move_items(int n, char src, char dest, char temp, std::vector<std::string> &result) {
    // If n is 1, moves item from starting point directly to destination. Updates the vector with the move
    if (n==1) {
        MOVE_DISK(n, src, dest, result);
        return;
    }
    // Moves n-1 items from starting point to temp location, using the destination as the intermediate location. Stores the move in result
    move_items(n-1, src, temp, dest, result);
    // Moves the nth item from starting point to the destination and updates the result vector with the move
    MOVE_DISK(n, src, dest, result);
    // Moves n-1 items from the temp location to the destination, using the starting point as the intermediate location. Stores the move in result
    move_items(n-1, temp, dest, src, result);
}

void move_items(int n, char src, char dest, std::vector<std::string> &result) {
    move_items(n, src, dest, 'X', result); // Calls the helper method and uses 'X' as the temp
}

