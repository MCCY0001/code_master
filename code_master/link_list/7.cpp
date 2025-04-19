#include <iostream>

#include "list_node.h"

class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (headA == NULL || headB == NULL) return NULL;
    ListNode *pA = headA;
    ListNode *pB = headB;
    while (pA != pB) {
      pA = pA == NULL ? headB : pA->next;
      pB = pB == NULL ? headA : pB->next;
    }
    return pA;
  }
};
int main() {
  std::cout << "Hello World!" << std::endl;
  return 0;
}
