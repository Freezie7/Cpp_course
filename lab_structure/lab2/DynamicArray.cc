
#include <cstdlib>
#include <exception>
#include <iostream>
#include <stdexcept>

template <typename T>
DynamicArray<T>::DynamicArray() {
  this->capacity = 8;
  this->data = new T[this->capacity];
}
template <typename T>
DynamicArray<T>::DynamicArray(std::int64_t capacity) {
  // check if user is dumb
  if (capacity < 1) {
    throw std::invalid_argument("Capacity < 1"); // https://en.cppreference.com/w/cpp/error/exception.html
    // std::exception like an animal
    // std::invalid_argument like a dog (heir of animal)
  }
  this->capacity = capacity;
  this->data = new T[this->capacity];
}

template <typename T>
DynamicArray<T>::DynamicArray(DynamicArray& other) {
  this->size = other.size;
  this->capacity = other.capacity;
  this->data = new T[this->capacity]; // (*this).data

  for (int i = 0; i <= size; ++i) {
    this->data[i] = other.data[i];
  }
}

template <typename T>
DynamicArray<T>::~DynamicArray() {
  // deallocate if allocated
  if (this->data) {
    delete[] this->data;
  }
}

template <typename T>
bool DynamicArray<T>::isEmpty(){
    return size == -1;
}

template <typename T>
void DynamicArray<T>::push_back(T x) {
  // reallocate memory
  // increase capacity
  // copy data
  // dealloc old
  // assign new to old
  if (size + 1 >= capacity) {
    std::int64_t newCapacity = capacity * 2;
    T* tempArray = new T[newCapacity];
    for (int i = 0; i < capacity; ++i) {
      tempArray[i] = data[i];
    }
    delete[] data;
    data = tempArray;
    capacity = newCapacity;
  }
  data[++size] = x;
}

template <typename T>
void DynamicArray<T>::push_front(T x) {
  // reallocate memory
  // increase capacity
  // copy data
  // dealloc old
  // assign new to old
  if (size + 1 >= capacity) {
    std::int64_t newCapacity = capacity * 2;
    T* tempArray = new T[newCapacity];
    for (int i = 0; i < capacity; ++i) {
      tempArray[i+1] = data[i];
    }
    delete[] data;
    data = tempArray;
    capacity = newCapacity;
  }else {
    for (int i = size; i >= 0; --i) {
      data[i + 1] = data[i];
    }
  }
  
  data[0] = x;
  ++size;
}

template <typename T>
T DynamicArray<T>::front(){
  if (isEmpty()) {
    throw std::invalid_argument("Array is empty");
  }
  return data[0];
}

template <typename T>
T DynamicArray<T>::back(){
  if (isEmpty()) {
    throw std::invalid_argument("Array is empty");
  }
  return data[size];
}

template <typename T>
void DynamicArray<T>::insert(std::int64_t idx, T val) {
  if (idx < 0 || idx > size + 1) {
    throw std::invalid_argument("The index has gone beyond");
  }
  
  if (idx == 0) { //вставляем в начало
    push_front(val);
    return;
  }
  
  if (idx == size + 1) {//вставляем в конец
    push_back(val);
    return;
  }

  if (size + 1 >= capacity) {
    std::int64_t newCapacity = capacity * 2;
    T* tempArray = new T[newCapacity];

    for (int i = 0; i < idx; ++i) {
      tempArray[i] = data[i];
    }

    tempArray[idx] = val;

    for (int i = idx; i <= size; ++i) {
      tempArray[i + 1] = data[i];
    }

    delete[] data;
    data = tempArray;
    capacity = newCapacity;
  }else {
    for (int i = size; i >= idx; --i) {
      data[i + 1] = data[i];
    }
    data[idx] = val;
  }
  ++size;
}

template <typename T>
void DynamicArray<T>::delete_idx(std::int64_t idx) {
  if (isEmpty() || idx < 0 || idx > size) {
    throw std::invalid_argument("Index out of range");
  }

  for (int i = idx; i < size; ++i) {
    data[i] = data[i + 1];
  }
  
  --size;
}

template <typename T>
void DynamicArray<T>::erase_after(std::int64_t idx) {
  if (isEmpty() || idx < 0 || idx > size) {
    throw std::invalid_argument("Index out of range");
  }
  if (idx >= size) {
    return;
  }

  size = idx;//обрезаем
}

template <typename T>
void DynamicArray<T>::increase_capacity(std::int64_t newCapacity) {
  if (newCapacity <= capacity) {
    throw std::invalid_argument("The new capacity should be larger than the old one.");
  }

  T* tempArray = new T[newCapacity];
  
  for (int i = 0; i <= size; ++i) {
    tempArray[i] = data[i];
  }
  delete[] data;
  data = tempArray;
  capacity = newCapacity;
}

template <typename T>
void DynamicArray<T>::decrease_capacity(std::int64_t newCapacity) {
  if (newCapacity >= capacity) {
    throw std::invalid_argument("The new capacity must be smaller than the old one.");
  }

  T* tempArray = new T[newCapacity];
  for (int i = 0; i <= size; ++i) {
    tempArray[i] = data[i];
  }

  delete[] data;
  data = tempArray;
  capacity = newCapacity;
}

template <typename T>
T DynamicArray<T>::add(std::int64_t idx1, std::int64_t idx2) {
  if (idx1 > size || idx2 > size || idx1 < 0 || idx2 < 0) {
    throw std::invalid_argument("idx1 or idx2 out of range");
  }
  return data[idx1] + data[idx2];
}

template <typename T>
T DynamicArray<T>::max() {
  if (isEmpty()) {
    throw std::invalid_argument("Empty array");
  }
  T currentMax = data[0];
  // T currentMax = std::numeric_limits<T>::lowest();
  for (int i = 0; i <= size; ++i) {
    if (data[i] >= currentMax) {
      currentMax = data[i];
    }
  }
  return currentMax;
}

template <typename T>
T DynamicArray<T>::min() {
  if (isEmpty()) {
    throw std::invalid_argument("Empty array");
  }
  T currentMin = data[0]; // -1 * 10^38
  // T currentMin = std::numeric_limits<T>::max();
  for (int i = 0; i <= size; ++i) {
    if (data[i] <= currentMin) {
      currentMin = data[i];
    }
  }
  return currentMin;
}

template <typename T>
void DynamicArray<T>::clear() {
  if (this->data) {
    delete[] this->data;
    this->data = nullptr;
  }
  size = -1;
  capacity = 8;
  this->data = new T[this->capacity];
}

template <typename T>
void DynamicArray<T>::reinitialize() {
  clear();
  data = new T[capacity](); // init with zeros
}

template <typename T>
void DynamicArray<T>::printData() {
  if (isEmpty()) {
    return;
  }
  for (int i = 0; i <= size; ++i) {
    std::cout << data[i] << " ";
  }
  std::cout << std::endl;
}

template <typename T>
T DynamicArray<T>::operator[](std::int64_t idx) {
  if (isEmpty() || idx < 0 || idx > size) {
    throw std::invalid_argument("Out of range");
  }
  return data[size - idx]; // Arabic operator[]
  // return data[idx];     // European operator[]
}

template <typename T>
T DynamicArray<T>::operator()() {
  if (isEmpty()) {
    return T();
  }
  T sum = 0;
  for (int i = 0; i <= size; ++i) {
    sum += data[i];
  }
  return sum;
}

template <typename T>
std::int64_t DynamicArray<T>::getLength(){
    return size + 1;
}
