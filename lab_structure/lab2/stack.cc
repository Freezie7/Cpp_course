#include <stdexcept>

template <typename T>
Stack<T>::Stack(std::int64_t size){
    this->max_size = size;
}

template <typename T>
bool Stack<T>::isEmpty() {
    return storage.isEmpty();
}

template <typename T>
void Stack<T>::push(T x) {
    if (this->storage.getLength() >= this->max_size) {
        throw std::overflow_error("Stack overflow");
    }
    this->storage.push_back(x);
}

template <typename T>
T Stack<T>::top() {
    if (isEmpty()) {
        throw std::logic_error("Stack is Empty"); 
    }
    return storage.back();
}

template <typename T>
T Stack<T>::pop() {
    if (isEmpty()) {
        throw std::logic_error("Stack is Empty");
    }
    T val = storage.back();
    this->storage.delete_idx(this->storage.getLength() - 1);
    return val;
}

template <typename T>
Stack<T>::~Stack() {}