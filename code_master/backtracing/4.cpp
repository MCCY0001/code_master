/**
 * @file 4.cpp
 * @author MCCY (mccy0001@gmail.com)
 * @brief 本文件用于解决 LeetCode 第 216 题 - 组合总和 III 问题。
 *        题目描述：找出所有相加之和为 n 的 k 个数的组合，这些组合需满足仅使用 1
 *        到 9 的数字，
 *        且每个数字最多使用一次。返回所有可能的有效组合列表，列表中不能包含重复组合，组合顺序任意。
 *        题目链接：https://leetcode-cn.com/problems/combination-sum-iii/
 * @version 0.1
 * @date 2025-03-06
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <vector>

using namespace std;
class Solution {
 public:
  vector<vector<int>> result;
  vector<int> path;
  void backtrack(int k, int sum, int start_index) {
    if (path.size() == k) {
      if (sum == 0) {
        result.push_back(path);
      }
      return;
    }
    for (int i = start_index; i <= 9 - (k - path.size()) + 1; i++) {
      if (sum < i) {
        return;
      }
      path.push_back(i);
      backtrack(k, sum - i, i + 1);
      path.pop_back();
    }
  }
  vector<vector<int>> combinationSum3(int k, int n) {
    result.clear();
    path.clear();
    backtrack(k, n, 1);
    return result;
  }
};