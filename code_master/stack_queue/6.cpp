#include <functional>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// leetcode 150. 逆波兰表达式求值
// https://leetcode.cn/problems/evaluate-reverse-polish-notation/

class Solution {
 public:
  int evalRPN(vector<string>& tokens) {
    unordered_map<string, function<int(int, int)>> ops = {
        {"+", [](int a, int b) { return a + b; }},
        {"-", [](int a, int b) { return a - b; }},
        {"*", [](int a, int b) { return a * b; }},
        {"/", [](int a, int b) { return a / b; }},
    };
    stack<int> stk;
    for (string& token : tokens) {
      if (ops.count(token)) {
        int num2 = stk.top();
        stk.pop();
        int num1 = stk.top();
        stk.pop();
        stk.push(ops[token](num1, num2));
      } else {
        stk.push(stoi(token));
      }
    }
    return stk.top();
  }
};

int main() {
  Solution solution;
  vector<string> tokens = {"2", "1", "+", "3", "*"};
  int ans = solution.evalRPN(tokens);
  cout << ans << endl;
  return 0;
}
