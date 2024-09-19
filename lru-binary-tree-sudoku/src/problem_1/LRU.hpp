#pragma once

#include "array_map.h"
#include "util.h"

/*
 * Task 1.1:
 * In the video I learned about caching, which is the practice of saving information that is most likely to be reused by the computer in the part of the memory that is the quickest and simplest for the machine to gain access to
 * I learned that to carry out caching operations, 'cache eviction' can be used
 * Cache eviction can be achieved by creating an algorithm called the 'least recently used algorithm'
 * The 'least recently used algorithm' decides what items or information will not be needed again in the future or will be used the least by the machine
 * Additionally, I learned about self organizing lists and how they can be used with caching
 * Self organizing lists contain a list of information that can be rearranged in order based on the most recently used items or information
 * The most recently used pieces of information are moved to the front of the list
 * Lastly, I learned that self organizing lists are the second most optimized caching algorithm, and that clairvoyant is the theoretically the most optimized caching algorithm
 *
 */

template<typename T>
class LRUCache;

template<typename T>
class ListNode {
private:
    std::string key;
    T value;
    ListNode<T> *next;

public:
    ListNode() : next(nullptr) {}

    ListNode(const std::string &key, const T &value) : key(key), value(value), next(nullptr) {}

    friend class LRUCache<T>;
};

// I got help from Peng and GPT writing the code in this class

template<typename T>
class LRUCache {
private:
    int capacity;

    int num_of_entry;

    ArrayMap<std::string, ListNode<T> *> *map;

    ListNode<T> head; // dummy head node

public:

    explicit LRUCache(int capacity) : capacity(capacity), num_of_entry(0) {
        map = new ArrayMap<std::string, ListNode<T> *>(capacity);
    }

    int get_capacity() {
        return capacity;
    }

    bool get(const std::string &key, T &value);

    bool remove(const std::string &key);

    bool put(const std::string &key, const T &value, T &evicted_value);


    virtual ~LRUCache() {
        ListNode<T> *curr = head.next; // creates a pointer to the first node in the linked list

        // loops through the linked list as long as the next node is not null
        while (curr != nullptr) {
            ListNode<T> *next = curr->next; // creates a pointer to the next node after the current node
            delete curr; //deletes the current node
            curr = next; // moves to the next node in the linked list
        }
        delete map; // deallocates memory for the map
    }
};

/*
 * removes the item with the given name as the key
 */
template<typename T>
bool LRUCache<T>::remove(const std::string &key) {
    ListNode<T> *node = nullptr; // declares a pointer to ListNode<T>

    // checks if they key is in the map, return false if not
    if (!map->get(key,node)) {
        return false;
    }

    ListNode<T> *prev = &head; // initializes a pointer for previous to the dummy head node

    if (prev->next == node) { // checks if the next node is the node to be removed
        prev->next = node->next; // removes the node from the linked list
        delete node; // deallocates memory for the node
    }

    map->remove(key); // removes the key from the map
    return true; // returns true if item is removed
}

template<typename T>
bool LRUCache<T>::put(const std::string &key, const T &value, T &evicted_value) {
    ListNode<T> *new_node = new ListNode<T>(key, value); // creates a new node with the provided key and value
    new_node->next = head.next; // sets the new node's 'next' pointer to the first node in the linked list
    head.next = new_node; // sets the dummy node's 'next' pointer to the new node, moving the new node to the front of the list
    map->put(key, new_node); // adds the new key and node value to the map

    // checks if the number of entries is equal to the cache's capacity
    if (num_of_entry == capacity) {
        ListNode<T> *prev = &head; // initializes a pointer for previous to the dummy head node

        while (prev->next->next != nullptr) { // traverses the linked list and finds the node before the least recently used (LRU) node
            prev = prev->next; // points to the LRU node
        }

        ListNode<T> *node = nullptr; // declares a pointer to ListNode<T> to store the node associated with lru_key
        std::string lru_key = prev->next->key; // gets the key of the least recently used node
        map->get(lru_key,node); // gets the node corresponding to lru_key
        evicted_value = node->value; // stores the value of the least recently used node
        prev->next = node->next; // removes the node from the linked list
        remove(lru_key); // calls 'remove' to remove the least recently used node from the map
        delete node; // deallocates memory for the node
        return true; // returns true since eviction occurred
    }

    num_of_entry++;  // increments the number of entries in the cache
    return false; // returns false since no eviction occurred
}

/*
 * get finds and return the item based on name
 */
template<typename T>
bool LRUCache<T>::get(const std::string &key, T &result) {
    ListNode<T> *node = nullptr; // declares a pointer to ListNode<T> to store the node associated with the key

    // checks if the key is in the map, returns false if not
    if (!map->get(key, node)) {
        return false;
    }

    result = node->value;  // if key is found, sets result to the value of the node
    return true; // returns true if item is found
}