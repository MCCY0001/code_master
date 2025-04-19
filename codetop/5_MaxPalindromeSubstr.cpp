#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string longestPalindrome(string s) {
    int size = s.size();
    int start = 0, max_len = 1;

    vector<vector<int>> dp(size, vector<int>(size, false));
    for (int i = 0; i < size; ++i) {
      dp[i][i] = true;
      if (i < size - 1 && s[i] == s[i + 1]) {
        dp[i][i + 1] = true;
        if (max_len < 2) {
          max_len = 2;
          start = i;
        }
      }
    }

    for (int len = 3; len <= size; ++len) {
      for (int i = 0; i <= size - len; ++i) {
        int j = i + len - 1;
        if (s[i] == s[j] && dp[i + 1][j - 1]) {
          dp[i][j] = true;
          if (len > max_len) {
            max_len = len;
            start = i;
          }
        }
      }
    }
    return s.substr(start, max_len);
  }
};