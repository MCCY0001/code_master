#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;
    unordered_map<int, int> hash;
    for (size_t i = 0; i < nums.size(); ++i) {
      int num = nums[i];
      int diff = target - num;
      if (auto it = hash.find(diff); it != hash.end()) {
        res.push_back(it->second);
        res.push_back(i);
        return res;
      } else {
        hash[num] = i;
      }
    }
    return res;
  }
};

int main() {
  Solution solution;
  vector<int> nums = {2, 7, 11, 15};
  int target = 9;
  vector<int> res = solution.twoSum(nums, target);
  for (int num : res) {
    cout << num << " ";
  }
  return 0;
}