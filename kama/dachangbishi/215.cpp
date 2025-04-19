#include <climits>
#include <iostream>
#include <vector>

using namespace std;

void Solve() {
  int n;
  cin >> n;

  vector<int> arr(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  vector<int> dp(n, INT_MAX);
  dp[0] = 1;
  for (int i = 1; i < n; ++i) {
    dp[i] = dp[i - 1] + 1;
    int min_val = INT_MAX;
    for (int j = 0; j < i; ++j) {
      if (arr[j] != arr[i]) {
        int cost = j == 0 ? 1 : dp[j - 1] + 1;
        min_val = min(min_val, cost);
      }
    }
    dp[i] = min(dp[i], min_val);
  }

  cout << dp[n - 1] << '\n';
}

int main() {
  Solve();
  return 0;
}