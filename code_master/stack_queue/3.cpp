#include <queue>

using namespace std;

// leetcode 225. Implement Stack using Queues
// https://leetcode-cn.com/problems/implement-stack-using-queues/

class MyStack {
 public:
  queue<int> que;
  MyStack() {}

  void push(int x) {
    que.push(x);
    int n = que.size();
    while (n-- > 1) {
      que.push(que.front());
      que.pop();
    }
  }

  int pop() {
    int x = que.front();
    que.pop();
    return x;
  }

  int top() { return que.front(); }

  bool empty() { return que.empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main() { return 0; }
