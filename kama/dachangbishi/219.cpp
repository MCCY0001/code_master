#include <iostream>
#include <unordered_map>

using namespace std;

void Solve() {
  int n;
  cin >> n;

  int* nums = new int[n + 1];
  char* colors = new char[n + 1];
  unordered_map<int, int> pos_map;
  for (int i = 1; i <= n; ++i) {
    cin >> nums[i];
    pos_map[nums[i]] = i;
  }
  for (int i = 1; i <= n; ++i) {
    cin >> colors[i];
  }

  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (nums[i] == i) {
      continue;
    } else {
      int right_pos = pos_map[i];
      if (colors[i] != 'R' || colors[right_pos] != 'R') {
        cout << -1 << '\n';
        delete[] nums;
        delete[] colors;
        return;
      } else {
        swap(nums[i], nums[right_pos]);
        pos_map[nums[i]] = i;
        pos_map[nums[right_pos]] = right_pos;
        ++ans;
      }
    }
  }

  cout << ans << '\n';

  delete[] nums;
  delete[] colors;
  return;
}

int main() {
  Solve();
  return 0;
}