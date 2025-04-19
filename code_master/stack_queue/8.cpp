#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

// leetcode 347. 前 K 个高频元素

// URL_ADDRESS// https://leetcode-cn.com/problems/top-k-frequent-elements/

class Compare {
  // 如果表达式 comp(a, b) 为 true，那么算法会认为 a 应该排在 b
  // 的后面（也就是说，a 的优先级低于 b）。
 public:
  bool operator()(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
  }
};

class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
      map[nums[i]]++;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> q;
    for (auto it = map.begin(); it != map.end(); it++) {
      q.push(*it);
      if (q.size() > k) {
        q.pop();
      }
    }
    vector<int> ans;
    while (!q.empty()) {
      ans.push_back(q.top().first);
      q.pop();
    }
    return ans;
  }
};

int main() {
  Solution solution;
  vector<int> nums = {1, 1, 1, 2, 2, 3};
  int k = 2;
  vector<int> ans = solution.topKFrequent(nums, k);
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  return 0;
}
