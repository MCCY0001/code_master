#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> num_map;
    for (int i = 0; i < nums.size(); ++i) {
      int diff = target - nums[i];
      if (num_map.count(diff)) {
        return {i, num_map[diff]};
      }
      num_map[nums[i]] = i;
    }
    return {};
  }
};