#include <iostream>

#include "list_node.h"

class Solution {
 public:
  // ListNode* swapPairs(ListNode* head) {
  //   if (head == nullptr || head->next == nullptr) return head;
  //   ListNode* next = head->next;
  //   head->next = swapPairs(next->next);
  //   next->next = head;
  //   return next;
  // }
  ListNode* swapPairs(ListNode* head) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* cur = dummy;
    while (cur->next != nullptr && cur->next->next != nullptr) {
      ListNode* temp = cur->next;
      ListNode* temp1 = cur->next->next->next;
      cur->next = temp->next;
      temp->next->next = temp;
      temp->next = temp1;
      cur = cur->next->next;
    }
    ListNode* res = dummy->next;
    delete dummy;
    return res;
  }
};

int main() {
  std::cout << "Hello World!" << std::endl;
  return 0;
}
