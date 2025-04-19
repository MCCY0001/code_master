#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> intersection(const vector<int>& nums1,
                           const vector<int>& nums2) const {
    unordered_map<int, int> record;
    for (const auto& num : nums1) {
      record[num] = 1;
    }
    vector<int> result;
    for (const auto& num : nums2) {
      if (record[num] == 1) {
        result.push_back(num);
        record[num] = 0;
      }
    }
    return result;
  }
};

int main() {
  Solution solution;
  auto result = solution.intersection({1, 2, 2, 1}, {2, 2});
  return 0;
}