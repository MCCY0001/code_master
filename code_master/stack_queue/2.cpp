#include <stack>

using namespace std;

// leetcode 232. Implement Queue using Stacks

class MyQueue {
 public:
  stack<int> stackIn;
  stack<int> stackOut;
  MyQueue() {}

  void push(int x) { stackIn.push(x); }

  int pop() {
    if (stackOut.empty()) {
      while (!stackIn.empty()) {
        stackOut.push(stackIn.top());
        stackIn.pop();
      }
    }
    int result = stackOut.top();
    stackOut.pop();
    return result;
  }

  int peek() {
    int res = this->pop();
    stackOut.push(res);
    return res;
  }

  bool empty() { return stackIn.empty() && stackOut.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main() { return 0; }
