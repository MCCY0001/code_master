#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int val) : val(val), next(nullptr) {}
};

vector<string> Split(const string& str, const string& delimiter) {
  vector<string> tokens;
  int start = 0, end = 0;
  while ((end = str.find(delimiter, start)) != string::npos) {
    tokens.push_back(str.substr(start, end - start));
    start = end + delimiter.length();
  }
  tokens.push_back(str.substr(start));
  return tokens;
}

ListNode* Reverse(ListNode* head) {
  ListNode* prev = nullptr;
  ListNode* curr = head;
  while (curr) {
    ListNode* next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  return prev;
}

ListNode* FoldList(ListNode* head) {
  if (!head || !head->next) return head;
  ListNode* prev = nullptr;
  ListNode* slow = head;
  ListNode* fast = head;

  while (fast && fast->next) {
    prev = slow;
    slow = slow->next;
    fast = fast->next->next;
  }

  ListNode* left = head;
  ListNode* right = nullptr;
  ListNode* middle = nullptr;

  // 奇数
  if (fast) {
    middle = slow;
    prev->next = nullptr;
    right = slow->next;
    middle->next = nullptr;
  } else {
    prev->next = nullptr;
    right = slow;
  }

  left = Reverse(left);
  right = Reverse(right);

  if (middle) {  // 奇数长度链表
    ListNode* temp = left;
    while (temp->next) {
      temp = temp->next;
    }
    temp->next = middle;
    middle->next = right;
  } else {  // 偶数长度链表
    ListNode* temp = left;
    while (temp->next) {
      temp = temp->next;
    }
    temp->next = right;
  }
  return left;
}

int main() {
  string input;
  getline(cin, input);
  if (input.empty()) {
    cout << "";
    return 0;
  }
  vector<string> tokens = Split(input, "->");
  ListNode dummy(0);
  ListNode* tail = &dummy;
  for (const std::string& token : tokens) {
    if (token == "") {
      continue;
    }
    int nums = stoi(token);
    tail->next = new ListNode(nums);
    tail = tail->next;
  }
  ostringstream oss;
  ListNode* head = FoldList(dummy.next);
  bool first = true;
  while (head) {
    if (!first) {
      oss << "->";
    }
    first = false;
    oss << head->val;
    head = head->next;
  }
  cout << oss.str();
  return 0;
}