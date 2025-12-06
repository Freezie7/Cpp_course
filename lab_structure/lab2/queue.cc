#include <stdexcept>

template <typename T>
Queue<T>::Queue(std::int64_t capacity): Stack1(capacity), Stack2(capacity){
        this->maxCapacity = capacity;
}

template <typename T>
void Queue<T>::enqueue(T x) {
    if (size() >= maxCapacity) {
        throw std::overflow_error("Queue Overflow");
    }
    
    Stack1.push(x);
}

template <typename T>
T Queue<T>::dequeue() {
    if (isEmpty()) {
        throw std::logic_error("Queue is Empty");
    }

    if (Stack2.isEmpty()) {
        while (!Stack1.isEmpty()) {
            Stack2.push(Stack1.pop());
        }
    }

    T val = Stack2.pop();
    return val;
}

template <typename T>
bool Queue<T>::isEmpty() {
    return Stack1.isEmpty() && Stack2.isEmpty();
}

template <typename T>
std::int64_t Queue<T>::size() {
    return Stack1.getSize() + Stack2.getSize();
}

template <typename T>
void Queue<T>::print() {
    
    std::cout << "Stack1: ";
    Stack1.print(); 
    
    std::cout << "\n" << "Stack2: ";
    Stack2.print();
}