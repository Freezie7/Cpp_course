#ifndef QUEUE_H
#define QUEUE_H

#include "stack.h" // Очередь строится на базе Стека
#include <stdexcept>

template <typename T>
class Queue {
private:
    Stack<T> Stack1;
    Stack<T> Stack2;
    std::int64_t maxCapacity;
    

public:
    Queue(std::int64_t capacity);

    void enqueue(T x);
    T dequeue();
    void print();
    bool isEmpty(); 
    std::int64_t size(); 
};

#include "queue.cc"

#endif // QUEUE_H