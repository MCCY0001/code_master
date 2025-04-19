#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void reverseString(vector<char>& s) {
    for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
      std::swap(s[i], s[j]);
    }
  }
};

int main() {
  Solution solution;
  vector<char> s;
  s.push_back('h');
  s.push_back('e');
  s.push_back('l');
  s.push_back('l');
  s.push_back('o');
  solution.reverseString(s);
  for (int i = 0; i < s.size(); i++) {
    cout << s[i] << " ";
  }
  return 0;
}
