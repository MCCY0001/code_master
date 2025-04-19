/**
 * @file 3.cpp
 * @author MCCY (mccy0001@gmail.com)
 * @brief 本文件用于解决 LeetCode 第 77 题 - 组合问题。
 *        题目描述：给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的
 *        k 个数的组合。
 *        题目链接：https://leetcode.cn/problems/combinations/description/
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
  void backtrack(int n, int k, int depth) {
    if (path.size() == k) {
      result.push_back(path);
      return;
    }
    // k - path.size() >= n - i + 1 才有意义，如果不满足那就没必要再遍历了
    for (int i = depth; i <= n - (k - path.size()) + 1; i++) {
      path.push_back(i);
      backtrack(n, k, i + 1);
      path.pop_back();
    }
  }
  vector<vector<int>> combine(int n, int k) {
    backtrack(n, k, 1);
    return result;
  }
};