#ifndef _MONOTONIC_QUEUE_H_
#define _MONOTONIC_QUEUE_H_

#include <deque>

template <typename T, typename Compare = std::greater<T>>
class MonotonicQueue {
 public:
  MonotonicQueue() : compare_(Compare()) {}
  ~MonotonicQueue() {}

  void Push(const T& value) {
    while (!data_.empty() && compare_(value, data_.back())) {
      data_.pop_back();
    }
    data_.push_back(value);
  }

  void Pop(const T& value) {
    if (!data_.empty() && value == data_.front()) {
      data_.pop_front();
    }
  }

  const T& Front() const { return data_.front(); }

  bool Empty() const { return data_.empty(); }

  size_t Size() const { return data_.size(); }

 private:
  std::deque<T> data_;
  Compare compare_;
};

#endif