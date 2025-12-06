#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <cstdint>
#include <stdexcept>

template <typename T>
class DynamicArray {
private:
  T* data;
  std::int64_t size = -1; // actual (last occupied)
  std::int64_t capacity; // max

public:
  DynamicArray(); // default ctor
  DynamicArray(std::int64_t capacity); // parametrized ctor
  DynamicArray(DynamicArray& other);
  ~DynamicArray(); // destructor

  void push_back(T x);
  T add(std::int64_t idx1, std::int64_t idx2);
  T max();
  T min();
  void push_front(T x);
  T front();
  T back();
  void insert(std::int64_t idx, T val);
  void delete_idx(std::int64_t idx);
  void erase_after(std::int64_t idx);
  void increase_capacity(std::int64_t newCapacity);
  void decrease_capacity(std::int64_t newCapacity);
  void clear(); // deallocate the data
  void reinitialize(); // restore to default
  void printData();

  bool isEmpty();
  std::int64_t getLength();

  T operator[](std::int64_t idx);
  T operator()();
};

#include "DynamicArray.cc"
#endif // DYNAMIC_ARRAY_H