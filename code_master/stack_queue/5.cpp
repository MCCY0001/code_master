#include <iostream>
#include <stack>
#include <string>

using namespace std;

// 1047. 删除字符串中的所有相邻重复项
// https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string/

class Solution {
 public:
  string removeDuplicates(string s) {
    stack<char> stk;
    for (char ch : s) {
      if (!stk.empty() && stk.top() == ch) {
        stk.pop();
      } else {
        stk.push(ch);
      }
    }
    string ans;
    while (!stk.empty()) {
      ans = stk.top() + ans;
      stk.pop();
    }
    return ans;
  }
};

int main() {
  Solution solution;
  string ans = solution.removeDuplicates("abbaca");
  cout << ans << endl;
  return 0;
}
