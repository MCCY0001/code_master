/**
 * @file 2.cpp
 * @author MCCY (mccy0001@gmail.com)
 * @brief 本文件用于解决 LeetCode 第 455 题 - 分发饼干问题。
 *        题目描述：假设你是一位很棒的家长，想要给你的孩子们一些小饼干。
 *        每个孩子 i 都有一个胃口值 g[i]，每块饼干 j 都有一个尺寸 s[j]。
 *        如果 s[j] >= g[i]，则可以将饼干 j 分配给孩子 i，孩子 i 会得到满足。
 *        你的目标是让尽可能多的孩子得到满足，并输出这个最大数量。
 *        题目链接：https://leetcode.cn/problems/assign-cookies/
 * @version 0.1
 * @date 2025-03-06
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int findContentChildren(vector<int>& g, vector<int>& s) {
    int result = 0;
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int child = g.size() - 1;
    int cookie = s.size() - 1;
    while (child >= 0 && cookie >= 0) {
      if (s[cookie] >= g[child]) {
        result++;
        child--;
        cookie--;
      } else {
        child--;
      }
    }
    return result;
  }
};
