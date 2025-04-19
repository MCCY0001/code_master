#include <algorithm>
#include <set>
#include <vector>


using namespace std;

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    int n = nums.size();
    if (n < 3) {
      return result;
    }

    sort(nums.begin(), nums.end());
    for (int i = 0; i < n - 2; ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }

      int target = -nums[i];
      int left = i + 1, right = n - 1;
      while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == target) {
          result.push_back({nums[i], nums[left], nums[right]});

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
    return result;
  }
};

class Solution2 {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    set<vector<int>> vector_set;
    int n = nums.size();
    if (n < 3) {
      return result;
    }

    sort(nums.begin(), nums.end());
    for (int i = 0; i < n - 2; ++i) {
      int target = -nums[i];
      int left = i + 1, right = n - 1;
      while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == target) {
          vector_set.insert({nums[i], nums[left], nums[right]});
          ++left;
          --right;
        } else if (sum < target) {
          ++left;
        } else {
          --right;
        }
      }
    }

    for (auto vector : vector_set) {
      result.push_back(vector);
    }
    return result;
  }
};