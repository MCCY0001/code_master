#include <iostream>

#include "list_node.h"

class Solution {
 public:
  ListNode* reserve(ListNode* pre, ListNode* cur) {
    if (cur == nullptr) {
      return pre;
    }
    ListNode* temp = cur->next;
    cur->next = pre;
    return reserve(cur, temp);
  }
  ListNode* reverseList(ListNode* head) {
    // ListNode* pre = nullptr;
    // ListNode* cur = head;
    // ListNode* next;
    // while (cur) {
    //   next = cur->next;
    //   cur->next = pre;
    //   pre = cur;
    //   cur = next;
    // }
    // return pre;
    return reserve(nullptr, head);
  }
};

int main() {
  std::cout << "Hello World!" << std::endl;
  return 0;
}
