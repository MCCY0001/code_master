#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

const int MOD = 1000000000;

void Solve() {
  int n;
  cin >> n;

  vector<int> nums(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> nums[i];
  }

  int max_like = *max_element(nums.begin(), nums.end());
  int sum_like = accumulate(nums.begin(), nums.end(), 0);

  vector<int> res(n, 0);
  if (n == 1) {
    res[0] = nums[0];
    for (auto i : res) {
      cout << i << '\n';
    }
    return;
  } else if (n == 2) {
    for (int i = 0; i < n; ++i) {
      if (nums[i] == max_like) {
        res[i] = sum_like;
      } else if (nums[i] == max_like - 1) {
        res[i] = sum_like + 1;
      } else {
        res[i] = -1;
      }
    }
    for (auto i : res) {
      cout << i << '\n';
    }
    return;
  } else {
    auto Check = [n, sum_like](int k, int x) {
      int l1 = k - x;
      int l2 = k * (n - 1) - (sum_like - x);
      return l1 <= l2 + 1;
    };

    for (int i = 0; i < n; ++i) {
      if (nums[i] == max_like) {
        res[i] = sum_like;
        continue;
      }

      int left = max_like, right = MOD;
      int mid = left + ((right - left) >> 1);
      while (left <= right) {
        if (Check(mid, nums[i])) {
          right = mid - 1;
        } else {
          left = mid + 1;
        }
      }

      res[i] = sum_like + 2 * (left - nums[i]) - 1;
    }

    for (auto i : res) {
      cout << i << '\n';
    }
    return;
  }
}

int main() {
  Solve();
  return 0;
}
