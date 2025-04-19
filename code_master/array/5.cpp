#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  /**
   * @brief 找出满足和大于等于目标值的最短子数组的长度
   *
   * 此函数使用滑动窗口算法，在给定的整数向量中找出和大于等于目标值的最短连续子数组的长度。
   * 如果不存在这样的子数组，则返回 0。
   *
   * @param target 目标和，需要子数组的和大于等于该值
   * @param nums 包含整数的向量，用于查找满足条件的子数组
   * @return int 满足条件的最短子数组的长度，如果不存在则返回 0
   */
  int minSubArrayLen(int target, vector<int>& nums) {
    // 初始化结果为最大整数值，用于后续比较
    int result = INT_MAX;
    // 初始化当前子数组的和
    int sum = 0;
    // 滑动窗口的左边界
    int i = 0;
    // 当前子数组的长度
    int sub_length = 0;
    // 遍历数组，j 为滑动窗口的右边界
    for (int j = 0; j < nums.size(); j++) {
      // 累加当前元素到子数组的和
      sum += nums[j];
      // 当子数组的和大于等于目标值时，尝试缩小窗口
      while (sum >= target) {
        // 计算当前子数组的长度
        sub_length = (j - i + 1);
        // 更新最短子数组的长度
        result = result < sub_length ? result : sub_length;
        // 从子数组的和中减去左边界元素
        sum -= nums[i];
        // 左边界右移
        i++;
      }
    }
    // 如果结果仍为最大整数值，说明不存在满足条件的子数组，返回 0
    return result == INT_MAX ? 0 : result;
  }
};

int main() {
  Solution solution;
  vector<int> nums = {2, 3, 1, 2, 4, 3};
  int target = 7;
  int result = solution.minSubArrayLen(target, nums);
  cout << result << endl;
  return 0;
}