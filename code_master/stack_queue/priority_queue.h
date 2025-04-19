#ifndef _PRIORITY_QUEUE_H_
#define _PRIORITY_QUEUE_H_

#include <functional>
#include <stdexcept>
#include <vector>

template <typename T>
class Compare {
 public:
  bool operator()(const T& a, const T& b) const { return a < b; }
};

template <typename T, typename Compare = std::less<T>>
class Heap {
 public:
  Heap() : compare_(Compare()) {}
  explicit Heap(const Compare& comp) : compare_(comp) {}

  void Push(const T& value) {
    data_.push_back(value);
    SiftUp(data_.size() - 1);
  }

  void Pop() {
    if (Empty()) {
      throw std::out_of_range("Heap is empty.");
    }
    data_[0] = data_.back();
    data_.pop_back();
    if (!Empty()) {
      SiftDown(0);
    }
  }

  const T& Top() const {
    if (Empty()) {
      throw std::out_of_range("Heap is empty.");
    }
    return data_[0];
  }

  bool Empty() const { return data_.empty(); }

  size_t Size() const { return data_.size(); }

  // 自底向上建堆函数
  template <typename InputIterator>
  void BuildHeapBottomUp(InputIterator first, InputIterator last) {
    data_.assign(first, last);
    size_t n = data_.size();
    // 从最后一个非叶子节点开始
    for (size_t i = (n - 2) / 2; i < n; --i) {
      SiftDown(i);
    }
  }

  // 堆排序函数
  template <typename OutputIterator>
  void HeapSort(OutputIterator result) {
    size_t n = data_.size();
    std::vector<T> temp = data_;
    for (size_t i = n - 1; i > 0; --i) {
      std::swap(temp[0], temp[i]);
      // 调整剩余元素为新的堆，传入剩余未排序部分的大小
      int index = 0;
      while (true) {
        size_t left = 2 * index + 1;
        size_t right = 2 * index + 2;
        size_t best = index;
        if (left < i && compare_(temp[left], temp[best])) {
          best = left;
        }
        if (right < i && compare_(temp[right], temp[best])) {
          best = right;
        }
        if (best != index) {
          std::swap(temp[index], temp[best]);
          index = best;
        } else {
          break;
        }
      }
    }
    std::copy(temp.begin(), temp.end(), result);
  }

 private:
  std::vector<T> data_;
  Compare compare_;

  void SiftUp(size_t index) {
    while (index > 0) {
      size_t parent = (index - 1) / 2;
      if (compare_(data_[index], data_[parent])) {
        std::swap(data_[index], data_[parent]);
        index = parent;
      } else {
        break;
      }
    }
  }

  void SiftDown(size_t index) {
    size_t n = data_.size();
    while (true) {
      size_t left = 2 * index + 1;
      size_t right = 2 * index + 2;
      size_t best = index;
      if (left < n && compare_(data_[left], data_[best])) {
        best = left;
      }
      if (right < n && compare_(data_[right], data_[best])) {
        best = right;
      }
      if (best != index) {
        std::swap(data_[index], data_[best]);
        index = best;
      } else {
        break;
      }
    }
  }
};

template <typename T, typename Compare = std::less<T>>
class PriorityQueue {
 public:
  void Push(const T& value) { heap_.Push(value); }

  void Pop() { heap_.Pop(); }

  const T& Top() const { return heap_.Top(); }

  bool Empty() const { return heap_.Empty(); }

  size_t Size() const { return heap_.Size(); }

  template <typename InputIterator>
  void BuildHeap(InputIterator first, InputIterator last) {
    heap_.BuildHeapBottomUp(first, last);
  }

  template <typename OutputIterator>
  void HeapSort(OutputIterator result) {
    heap_.HeapSort(result);
  }

 private:
  Heap<T, Compare> heap_;
};

#endif  // _PRIORITY_QUEUE_H_
