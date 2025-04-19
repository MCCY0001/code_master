#include <iostream>
#include <vector>

// 基数排序函数定义
/**
 * @brief 对向量中的元素进行基数排序
 *
 * 此函数使用基数排序算法对给定向量中的元素进行排序。
 * 基数排序是一种非比较排序算法，它根据元素的每一位进行排序，
 * 从最低有效位开始，依次对每一位进行计数排序。
 *
 * @param nums 待排序的整数向量
 */
void RadixSort(std::vector<int>& nums) {
  if (nums.empty()) return;

  // 找到最大值，确定最大位数
  int max_num = *std::max_element(nums.begin(), nums.end());

  // 从最低位开始，依次对每一位进行计数排序
  for (int exp = 1; max_num / exp > 0; exp *= 10) {
    std::vector<int> output(nums.size());
    std::vector<int> count(10, 0);

    // 统计每个桶中的元素个数
    for (int num : nums) {
      count[(num / exp) % 10]++;
    }

    // 计算每个桶的累积个数
    for (int i = 1; i < 10; i++) {
      count[i] += count[i - 1];
    }

    // 将元素放入输出数组
    for (int i = nums.size() - 1; i >= 0; i--) {
      output[count[(nums[i] / exp) % 10] - 1] = nums[i];
      count[(nums[i] / exp) % 10]--;
    }

    // 将输出数组复制回原数组
    for (int i = 0; i < nums.size(); i++) {
      nums[i] = output[i];
    }
  }
}

int main() {
  std::vector<int> arr = {34, 7, 23, 32, 5, 62, 32, 2, 1, 0};
  RadixSort(arr);

  // 输出排序后的数组
  std::cout << "Sorted array: ";
  for (int num : arr) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  return 0;
}
