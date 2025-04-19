#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    ranges::sort(nums);
    for (int i = 0; i < nums.size(); ++i) {
      /*
      这里是为了避免重复的三元组
      比如[-1, -1, 0, 1, 2, -1, -4]
      会出现[-1, 0, 1]和[-1, 0, 1]
      所以这里要跳过重复的数字
      */
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      int target = -nums[i];
      int left = i + 1;
      int right = nums.size() - 1;
      while (left < right) {
        if (nums[left] + nums[right] == target) {
          res.push_back({nums[i], nums[left], nums[right]});
          /*
          这里是为了确保最少会有一个三元组
          比如[-2, -1, -1, -1, 3, 3, 3]
          会出现[-2, -1, 3]和[-2, 3, -1]和[-2, 3, -1]
          所以这里要跳过重复的数字
          但是这里要注意，因为上面已经跳过了重复的数字
          所以这里要跳过重复的数字的下一个数字
          */
          while (left < right && nums[left] == nums[left + 1]) {
            ++left;
          }
          while (left < right && nums[right] == nums[right - 1]) {
            --right;
          }
          ++left;
          --right;
        } else if (nums[left] + nums[right] < target) {
          ++left;
        } else {
          --right;
        }
      }
    }
    return res;
  }
};

int main() {
  Solution solution;
  vector<int> nums = {-1, 0, 1, 2, -1, -4};
  vector<vector<int>> res = solution.threeSum(nums);
  for (const auto& r : res) {
    for (const auto& n : r) {
      cout << n << " ";
    }
    cout << endl;
  }
  return 0;
}