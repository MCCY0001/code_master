#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool canConstruct(string ransomNote, string magazine) {
    vector<int> hash(26, 0);
    for (const auto& c : magazine) {
      ++hash[c - 'a'];
    }
    for (const auto& c : ransomNote) {
      if (--hash[c - 'a'] < 0) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  Solution solution;
  string ransomNote = "aa";
  string magazine = "aab";
  bool res = solution.canConstruct(ransomNote, magazine);
  cout << res << endl;
  return 0;
}