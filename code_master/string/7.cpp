#include <iostream>
#include <vector>

using namespace std;
// leetcode 459. Repeated Substring Pattern

class Solution {
 public:
  // bool repeatedSubstringPattern(string s) {
  //   int len = s.size();
  //   for (int i = 1; i * 2 <= len; ++i) {
  //     if (len % i == 0) {
  //       bool match = true;
  //       for (int j = i; j < len; ++j) {
  //         if (s[j] != s[j - i]) {
  //           match = false;
  //           break;
  //         }
  //       }
  //     }
  //   }
  //   return false;
  // }
  // bool repeatedSubstringPattern(string s) {
  //   string t = s + s;
  //   t.erase(t.begin());
  //   t.erase(t.end() - 1);
  //   if (t.find(s) != string::npos) return true;
  //   return false;
  // }
  bool repeatedSubstringPattern(string s) {
    int len = s.size();
    vector<int> next(len, 0);
    for (int i = 1, j = 0; i < len; ++i) {
      while (j > 0 && s[i] != s[j]) {
        j = next[j - 1];
      }
      if (s[i] == s[j]) {
        ++j;
      }
      next[i] = j;
    }
    if (next[len - 1] != 0 && len % (len - (next[len - 1])) == 0) return true;
    return false;
  }
};

int main() {
  Solution S;
  string s = "abab";
  bool ans = S.repeatedSubstringPattern(s);
  cout << ans << endl;
  return 0;
}