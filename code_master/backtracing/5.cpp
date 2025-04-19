/**
 * @file 5.cpp
 * @author MCCY (mccy0001@gmail.com)
 * @brief 本文件用于解决 LeetCode 第 17 题 - 电话号码的字母组合问题。
 *        题目描述：给定一个仅包含数字 2-9
 *        的字符串，返回所有它能表示的字母组合。
 *        数字到字母的映射与电话按键相同。
 *        题目链接：https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/
 * @version 0.1
 * @date 2025-03-06
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> result;
  string path;
  const string letters_map[10] = {
      "",      // 0
      "",      // 1
      "abc",   // 2
      "def",   // 3
      "ghi",   // 4
      "jkl",   // 5
      "mno",   // 6
      "pqrs",  // 7
      "tuv",   // 8
      "wxyz",  // 9
  };
  void backtrack(string& digits, int index) {
    if (index == digits.size()) {
      result.push_back(path);
      return;
    }
    string letters = letters_map[digits[index] - '0'];
    for (char letter : letters) {
      path.push_back(letter);
      backtrack(digits, index + 1);
      path.pop_back();
    }
  }
  vector<string> letterCombinations(string digits) {
    result.clear();
    path = "";
    if (digits == "") {
      return result;
    }
    backtrack(digits, 0);
    return result;
  }
};