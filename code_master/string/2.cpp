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
  string reverseStr(string s, int k) {
    int n = s.size();
    for (int i = 0; i < n; i += 2 * k) {
      reverse(s, i, min(i + k - 1, n - 1));
    }
    return s;
  }
};

int main() {
  Solution solution;
  string s = "abcdefg";
  int k = 2;
  string result = solution.reverseStr(s, k);
  cout << result << endl;
  return 0;
}