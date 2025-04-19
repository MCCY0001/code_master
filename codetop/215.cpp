#include <stdexcept>
#include <vector>

using namespace std;

class MinHeap {
 public:
  int Size() { return heap_.size(); }
  void Push(int value) {
    heap_.push_back(value);
    HeapifyUp(heap_.size() - 1);
  }

  void Pop() {
    if (heap_.size() == 0) {
      throw out_of_range("Heap is empty");
    }
    heap_[0] = heap_.back();
    heap_.pop_back();
    HeapifyDown(0);
  }

  int Top() {
    if (heap_.size() == 0) {
      throw out_of_range("Heap is empty");
    }
    return heap_[0];
  }

 private:
  vector<int> heap_;

  int Parent(int index) { return (index - 1) / 2; }

  int LeftChild(int index) { return 2 * index + 1; }

  int RightChild(int index) { return 2 * index + 2; }

  void HeapifyDown(int index) {
    int size = Size();
    while (true) {
      int left = LeftChild(index);
      int right = RightChild(index);
      int best = index;

      if (left < size && heap_[left] < heap_[best]) {
        best = left;
      }

      if (right < size && heap_[right] < heap_[best]) {
        best = right;
      }

      if (best != index) {
        swap(heap_[best], heap_[index]);
        index = best;
      } else {
        break;
      }
    }
  }

  void HeapifyUp(int index) {
    while (index > 0) {
      int parent = Parent(index);
      if (heap_[parent] <= heap_[index]) {
        break;
      } else {
        swap(heap_[parent], heap_[index]);
        index = parent;
      }
    }
  }
};

class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    MinHeap min_heap;

    for (int num : nums) {
      min_heap.Push(num);
      if (min_heap.Size() > k) {
        min_heap.Pop();
      }
    }
    return min_heap.Top();
  }
};
