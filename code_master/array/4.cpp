#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> sortedSquares(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n);
    int left = 0, right = n - 1;
    for (int i = n - 1; i >= 0; i--) {
      if (abs(nums[left]) > abs(nums[right])) {
        result[i] = nums[left] * nums[left];
        left++;
      } else {
        result[i] = nums[right] * nums[right];
        right--;
      }
    }
    return result;
  }
};

int main() {
  Solution solution;
  vector<int> nums = {-4, -1, 0, 3, 10};
  vector<int> result = solution.sortedSquares(nums);
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << " ";
  }
  cout << endl;
  return 0;
}