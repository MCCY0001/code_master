#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  static bool Compare(vector<int>& a, vector<int>& b) { return a[0] < b[0]; }
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), Compare);

    vector<vector<int>> merged;
    for (int i = 0; i < intervals.size(); ++i) {
      int l = intervals[i][0], r = intervals[i][1];
      if (merged.empty() || merged.back()[1] < l) {
        merged.push_back({l, r});
      } else {
        merged.back()[1] = max(merged.back()[1], r);
      }
    }
    return merged;
  }
};
