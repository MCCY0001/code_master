#include <iostream>

using namespace std;

int GetDigitSum(int num) {
  int ans = 0;
  while (num) {
    ans += (num % 10);
    num /= 10;
  }
  return ans;
}

void Solve() {
  int n, q;
  cin >> n >> q;

  int* nums = new int[n];
  int* record = new int[n + 1];

  for (int i = 0; i < n; ++i) {
    cin >> nums[i];
    record[i + 1] = record[i] + GetDigitSum(nums[i]);
  }

  int* ans = new int[q];
  for (int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;

    ans[i] = (record[r] - record[l - 1]) % 3 == 0 ? 1 : 0;
  }

  for (int i = 0; i < q; ++i) {
    cout << (ans[i] == 1 ? "YES" : "NO") << '\n';
  }

  delete[] nums;
  delete[] record;
  delete[] ans;
  return;
}

int main() {
  Solve();
  return 0;
}