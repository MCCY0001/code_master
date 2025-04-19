#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3,
                   vector<int>& nums4) {
    int res = 0;
    unordered_map<int, int> hash;
    for (const auto& num1 : nums1) {
      for (const auto& num2 : nums2) {
        ++hash[num1 + num2];
      }
    }
    for (const auto& num3 : nums3) {
      for (const auto& num4 : nums4) {
        int diff = -(num3 + num4);
        if (auto it = hash.find(diff); it != hash.end()) {
          res += it->second;
        }
      }
    }
    return res;
  }
};

int main() {
  Solution solution;
  vector<int> nums1 = {1, 2};
  vector<int> nums2 = {-2, -1};
  vector<int> nums3 = {-1, 2};
  vector<int> nums4 = {0, 2};
  int res = solution.fourSumCount(nums1, nums2, nums3, nums4);
  cout << res << endl;
  return 0;
}