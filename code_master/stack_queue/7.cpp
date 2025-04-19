#include <deque>
#include <iostream>
#include <vector>

using namespace std;

// leetcode 239. 滑动窗口最大值

// URL_ADDRESS// https://leetcode.cn/problems/sliding-window-maximum/

// class MyQueue {
//  public:
//   deque<int> que;
//   void pop(int value) {
//     if (!que.empty() && value == que.front()) {
//       que.pop_front();
//     }
//   }
//   void push(int value) {
//     while (!que.empty() && value > que.back()) {
//       que.pop_back();
//     }
//     que.push_back(value);
//   }
//   int front() { return que.front(); }
// };

// class Solution {
//  public:
//   vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//     MyQueue que;
//     vector<int> result;
//     for (int i = 0; i < k; i++) {
//       que.push(nums[i]);
//     }
//     result.push_back(que.front());
//     for (int i = k; i < nums.size(); i++) {
//       que.pop(nums[i - k]);
//       que.push(nums[i]);
//       result.push_back(que.front());
//     }
//     return result;
//   }
// };

class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    deque<int> q;
    for (int i = 0; i < nums.size(); i++) {
      while (!q.empty() && nums[q.back()] < nums[i]) {
        q.pop_back();
      }
      q.push_back(i);
      /*
        队列中的元素是按照它们在数组
        nums中出现的顺序添加的，所以只需要检查队列的头部元素是否在当前滑动窗口中即可。
       */
      if (q.front() == i - k) {
        q.pop_front();
      }
      if (i >= k - 1) {
        ans.push_back(nums[q.front()]);
      }
    }
    return ans;
  }
};

int main() {
  Solution solution;
  vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
  int k = 3;
  vector<int> ans = solution.maxSlidingWindow(nums, k);
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}
