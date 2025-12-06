#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>
#include "DynamicArray.h"
#include <cstdint>


template <typename T>
class Stack
{
private:
    DynamicArray<T> storage;
    std::int64_t max_size;

    std::int64_t currentCount = 0;

public:
    Stack(std::int64_t max_size);
    bool isEmpty();
    void push(T x);
    void print();
    T pop();
    T top();
    std::int64_t getSize();
    ~Stack();
};

#include "stack.cc"

#endif
