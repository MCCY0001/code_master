#include <unordered_map>

using namespace std;

struct DLinkNode {
  int key, value;
  DLinkNode* prev;
  DLinkNode* next;
  DLinkNode() : key(0), value(0), prev(nullptr), next(nullptr) {}
  DLinkNode(int _key, int _value)
      : key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
 public:
  LRUCache(int capacity) : capacity_(capacity), size_(0) {
    head_ = new DLinkNode();
    tail_ = new DLinkNode();
    head_->next = tail_;
    tail_->prev = head_;
  }

  int get(int key) {
    if (!cache_.count(key)) {
      return -1;
    }
    DLinkNode* node = cache_[key];
    MoveToHead(node);
    return node->value;
  }

  void put(int key, int value) {
    if (!cache_.count(key)) {
      DLinkNode* node = new DLinkNode(key, value);
      cache_[key] = node;
      AddToHead(node);
      ++size_;
      if (size_ > capacity_) {
        DLinkNode* removed = RemoveTail();
        cache_.erase(removed->key);
        delete removed;
        --size_;
      }
    } else {
      DLinkNode* node = cache_[key];
      node->value = value;
      MoveToHead(node);
    }
  }

 private:
  unordered_map<int, DLinkNode*> cache_;
  DLinkNode* head_;
  DLinkNode* tail_;
  int size_;
  int capacity_;

  void DetachNode(DLinkNode* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }

  void MoveToHead(DLinkNode* node) {
    DetachNode(node);
    AddToHead(node);
  }

  void AddToHead(DLinkNode* node) {
    node->prev = head_;
    node->next = head_->next;
    head_->next->prev = node;
    head_->next = node;
  }

  DLinkNode* RemoveTail() {
    DLinkNode* node = tail_->prev;
    DetachNode(node);
    return node;
  }
};