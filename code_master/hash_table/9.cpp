#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    ranges::sort(nums);
    for (int k = 0; k < nums.size(); ++k) {
      if (nums[k] > target && nums[k] >= 0) {
        break;
      }
      if (k > 0 && nums[k] == nums[k - 1]) {
        continue;
      }
      for (int i = k + 1; i < nums.size(); ++i) {
        if (nums[k] + nums[i] > target && nums[k] + nums[i] >= 0) {
          break;
        }
        if (i > k + 1 && nums[i] == nums[i - 1]) {
          continue;
        }
        int left = i + 1;
        int right = nums.size() - 1;
        while (left < right) {
          long long sum = static_cast<long long>(nums[k]) + nums[i] +
                          nums[left] + nums[right];
          if (sum == target) {
            res.push_back({nums[k], nums[i], nums[left], nums[right]});
            while (left < right && nums[left] == nums[left + 1]) {
              ++left;
            }
            while (left < right && nums[right] == nums[right - 1]) {
              --right;
            }
            ++left;
            --right;
          } else if (sum < target) {
            ++left;
          } else {
            --right;
          }
        }
      }
    }
    return res;
  }
};

int main() {
  Solution solution;
  vector<int> nums;
  int target;
  vector<vector<int>> ans;
  nums = {1, 0, -1, 0, -2, 2};
  target = 0;
  ans = solution.fourSum(nums, target);
  for (const auto& a : ans) {
    for (const auto& n : a) {
      cout << n << " ";
    }
    cout << endl;
  }
  return 0;
}