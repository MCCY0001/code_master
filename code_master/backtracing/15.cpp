/**
 * @file 15.cpp
 * @author MCCY (mccy0001@gmail.com)
 * @brief 本文件用于解决 LeetCode 第 46 题 - 全排列问题。
 *        题目描述：给定一个不含重复数字的数组 nums ，返回其所有可能的全排列。
 *        你可以按任意顺序返回答案。
 *        题目链接：https://leetcode.cn/problems/permutations/description/
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
  void backtrack(vector<int>& nums, vector<bool>& visited) {
    if (path.size() == nums.size()) {
      result.push_back(path);
      return;
    }
    for (int i = 0; i < nums.size(); i++) {
      if (visited[i]) {
        continue;
      }
      visited[i] = true;
      path.push_back(nums[i]);
      backtrack(nums, visited);
      visited[i] = false;
      path.pop_back();
    }
  }
  vector<vector<int>> permute(vector<int>& nums) {
    result.clear();
    path.clear();
    vector<bool> visited(nums.size(), false);
    backtrack(nums, visited);
    return result;
  }
};