#include <iostream>
#include <vector>

using namespace std;
// leetcode 28

// class Solution {
//  public:
//   int strStr(string haystack, string needle) {
//     int n = haystack.size();
//     int m = needle.size();
//     for (int i = 0; i <= n - m; i++) {
//       bool flag = true;
//       for (int j = 0; j < m; j++) {
//         if (haystack[i + j] != needle[j]) {
//           flag = false;
//           break;
//         }
//       }
//       if (flag) {
//         return i;
//       }
//     }
//     return -1;
//   }
// };

class Solution {
 public:
  int strStr(string haystack, string needle) {
    int n = haystack.size();
    int m = needle.size();
    if (m == 0) {
      return 0;
    }
    vector<int> next(m, 0);
    for (int i = 1, j = 0; i < m; i++) {
      while (j && needle[i] != needle[j]) {
        j = next[j - 1];
      }
      if (needle[i] == needle[j]) {
        j++;
      }
      next[i] = j;
    }
    for (int i = 0, j = 0; i < n; i++) {
      while (j && haystack[i] != needle[j]) {
        j = next[j - 1];
      }
      if (haystack[i] == needle[j]) {
        j++;
      }
      if (j == m) {
        return i - m + 1;
      }
    }
    return -1;
  }
};

int main() {
  Solution S;
  string haystack = "hello";
  string needle = "ll";
  int ans = S.strStr(haystack, needle);
  cout << ans << endl;
}