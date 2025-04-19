#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

// 20. Valid Parentheses

// https://leetcode.cn/problems/valid-parentheses/

class Solution {
 public:
  bool isValid(string s) {
    int n = s.size();
    if (n % 2 == 1) {
      return false;
    }
    stack<char> stk;
    unordered_map<char, char> pairs = {
        {')', '('},
        {']', '['},
        {'}', '{'},
    };
    for (char ch : s) {
      if (pairs.count(ch)) {
        if (stk.empty() || stk.top() != pairs[ch]) {
          return false;
        }
        stk.pop();
      } else {
        stk.push(ch);
      }
    }
    return stk.empty();
  }
};

int main() {
  Solution solution;
  bool ans = solution.isValid("()");
  cout << ans << endl;
  return 0;
}
