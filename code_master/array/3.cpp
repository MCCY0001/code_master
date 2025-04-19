#include <iostream>
#include <vector>


class Solution {
 public:
  int removeElement(std::vector<int>& nums, int val) {
    int i = 0;
    for (int j = 0; j < nums.size(); j++) {
      if (nums[j] != val) {
        nums[i] = nums[j];
        i++;
      }
    }
    return i;
  }
};

int main() {
  Solution solution;
  std::vector<int> nums = {3, 2, 2, 3};
  int val = 3;
  int newSize = solution.removeElement(nums, val);
  // 输出新的数组长度和数组内容
  std::cout << "New size: " << newSize << std::endl;
  std::cout << "New array: ";
  for (int i = 0; i < newSize; i++) {
    std::cout << nums[i] << " ";
  }
  std::cout << std::endl;
  return 0;
}