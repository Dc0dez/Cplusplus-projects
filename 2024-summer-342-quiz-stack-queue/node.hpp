#pragma once

template<typename T>
class ListNode {
public:
    T val;
    ListNode<T> *next = nullptr;

    ListNode(T value) : val(value) {};

    ListNode(T value, ListNode<T> next) : val(value), next(next) {};
};