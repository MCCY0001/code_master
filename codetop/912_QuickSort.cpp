#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  void QuickSort(vector<int>& nums, int left, int right) {
    if (left >= right) {
      return;
    }
    int i = left, j = right;
    int pivot = nums[left + (right - left) / 2];

    while (i <= j) {
      while (nums[i] < pivot) {
        ++i;
      }
      while (nums[j] > pivot) {
        --j;
      }
      if (i <= j) {
        swap(nums[i], nums[j]);
        ++i;
        --j;
      }
    }
    QuickSort(nums, left, j);
    QuickSort(nums, i, right);
  }
  vector<int> sortArray(vector<int>& nums) {
    QuickSort(nums, 0, nums.size() - 1);
    return nums;
  }
};
