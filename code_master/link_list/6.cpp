#include <iostream>

#include "list_node.h"

class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy_head = new ListNode(0);
    dummy_head->next = head;
    ListNode* slow = dummy_head;
    ListNode* fast = dummy_head;
    while (n-- && fast != nullptr) {
      fast = fast->next;
    }
    fast = fast->next;
    while (fast != nullptr) {
      fast = fast->next;
      slow = slow->next;
    }
    ListNode* temp = slow->next;
    slow->next = temp->next;
    delete temp;
    ListNode* res = dummy_head->next;
    delete dummy_head;
    return res;
  }
};
int main() {
  std::cout << "Hello World!" << std::endl;
  return 0;
}
