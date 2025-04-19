#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
 public:
  void reverse(string& s, int left, int right) {
    while (left < right) {
      swap(s[left], s[right]);
      left++;
      right--;
    }
  }
  void removeExtraSpace(string& s) {
    int slow = 0;
    int fast = 0;
    while (s[fast] == ' ') {
      fast++;
    }
    for (; fast < s.size(); fast++) {
      if (s[fast] != ' ' || (s[fast] == ' ' && s[fast - 1] != ' ')) {
        s[slow++] = s[fast];
      }
    }
    if (slow - 1 > 0 && s[slow - 1] == ' ') {
      s.resize(slow - 1);
    } else {
      s.resize(slow);
    }
  }
  string reverseWords(string s) {
    removeExtraSpace(s);
    reverse(s, 0, s.size() - 1);
    int n = s.size();
    int start = 0;
    for (int i = 0; i <= n; i++) {
      if (i == n || s[i] == ' ') {
        reverse(s, start, i - 1);
        start = i + 1;
      }
    }
    return s;
  }
};

int main() {
  string s = "  hello world  ";
  Solution S;
  string ans = S.reverseWords(s);
  cout << ans << endl;
  return 0;
}