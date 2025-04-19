#include <iostream>
#include <vector>

// 快速排序函数定义
/**
 * @brief 对向量中的元素进行快速排序
 *
 * 此函数使用快速排序算法对给定向量中的元素进行排序。
 * 快速排序是一种分治算法，通过选择一个基准值，将数组分为两部分，
 * 使得左边部分的所有元素都小于等于基准值，右边部分的所有元素都大于等于基准值。
 * 然后递归地对左右两部分进行排序。
 *
 * @param arr 待排序的整数向量
 * @param left 排序区间的左边界
 * @param right 排序区间的右边界
 */
void QuickSort(std::vector<int>& arr, int left, int right) {
  if (left >= right) {
    return;
  }
  int i = left, j = right;
  int pivot = arr[left + (right - left) / 2];
  while (i <= j) {
    while (arr[i] < pivot) {
      ++i;
    }
    while (arr[j] > pivot) {
      --j;
    }
    if (i <= j) {
      std::swap(arr[i], arr[j]);
      ++i;
      --j;
    }
  }
  QuickSort(arr, left, j);
  QuickSort(arr, i, right);
}

int main() {
  int n;
  std::cin >> n;
  std::vector<int> arr(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> arr[i];
  }

  QuickSort(arr, 0, arr.size() - 1);

  std::cout << "Sorted array: ";
  for (int num : arr) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  return 0;
}