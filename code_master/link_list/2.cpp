#include <iostream>

#include "list_node.h"

class Solution {
 public:
  ListNode* removeElements(ListNode* head, int val) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* pre = dummy;
    ListNode* cur = head;
    while (cur) {
      if (cur->val == val) {
        pre->next = cur->next;
        delete cur;
        cur = pre->next;
      } else {
        pre = cur;
        cur = cur->next;
      }
    }
    ListNode* newHead = dummy->next;
    delete dummy;
    return newHead;
  }
};

int main() {
  Solution solution;
  ListNode* head = new ListNode(1);
  ListNode* node1 = new ListNode(2);
  ListNode* node2 = new ListNode(6);
  ListNode* node3 = new ListNode(3);
  ListNode* node4 = new ListNode(4);
  ListNode* node5 = new ListNode(5);
  ListNode* node6 = new ListNode(6);
  head->next = node1;
  node1->next = node2;
  node2->next = node3;
  node3->next = node4;
  node4->next = node5;
  node5->next = node6;
  ListNode* result = solution.removeElements(head, 6);
  while (result) {
    std::cout << result->val << " ";
    result = result->next;
  }
}
