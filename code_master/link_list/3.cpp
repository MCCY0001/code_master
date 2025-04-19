#include <iostream>

class MyLinkedList {
 public:
  struct LinkedNode {
    int val;
    LinkedNode* next;
    LinkedNode(int val) : val(val), next(nullptr) {}
  };
  MyLinkedList() {
    dummy_head_ = new LinkedNode(0);
    size_ = 0;
  }

  int get(int index) {
    if (index > size_ - 1 || index < 0) {
      return -1;
    }
    LinkedNode* cur = dummy_head_->next;
    while (index--) {
      cur = cur->next;
    }
    return cur->val;
  }

  void addAtHead(int val) {
    LinkedNode* newNode = new LinkedNode(val);
    newNode->next = dummy_head_->next;
    dummy_head_->next = newNode;
    size_++;
  }

  void addAtTail(int val) {
    LinkedNode* newNode = new LinkedNode(val);
    LinkedNode* cur = dummy_head_;
    while (cur->next != nullptr) {
      cur = cur->next;
    }
    cur->next = newNode;
    size_++;
  }

  void addAtIndex(int index, int val) {
    if (index > size_) {
      return;
    }
    if (index < 0) {
      index = 0;
    }
    LinkedNode* newNode = new LinkedNode(val);
    LinkedNode* cur = dummy_head_;
    while (index--) {
      cur = cur->next;
    }
    newNode->next = cur->next;
    cur->next = newNode;
    size_++;
  }

  void deleteAtIndex(int index) {
    if (index >= size_ || index < 0) {
      return;
    }
    LinkedNode* cur = dummy_head_;
    while (index--) {
      cur = cur->next;
    }
    LinkedNode* tmp = cur->next;
    cur->next = cur->next->next;
    delete tmp;
    size_--;
  }

 private:
  LinkedNode* dummy_head_;
  int size_;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main() {
  std::cout << "Hello World!" << std::endl;
  return 0;
}
