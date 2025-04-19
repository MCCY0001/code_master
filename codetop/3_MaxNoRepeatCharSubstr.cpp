#include <string>
#include <unordered_set>

using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int max_length = 0;
    unordered_set<char> char_set;
    int start = 0;
    for (int i = 0; i < s.size(); ++i) {
      while (char_set.find(s[i]) != char_set.end()) {
        char_set.erase(s[start]);
        ++start;
      }

      char_set.insert(s[i]);
      max_length = max(max_length, i - start + 1);
    }
    return max_length;
  }
};