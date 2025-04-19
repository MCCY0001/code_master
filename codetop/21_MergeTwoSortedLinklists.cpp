struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* dummy = new ListNode();
    ListNode* current = dummy;
    ListNode* node1 = list1;
    ListNode* node2 = list2;

    while (node1 && node2) {
      if (node1->val <= node2->val) {
        current->next = node1;
        node1 = node1->next;
      } else {
        current->next = node2;
        node2 = node2->next;
      }
      current = current->next;
    }

    if (node1) {
      current->next = node1;
    } else {
      current->next = node2;
    }

    ListNode* result = dummy->next;
    delete dummy;
    return result;
  }
};