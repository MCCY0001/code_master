#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 100000000;

void Solve() {
  int n, x;
  cin >> n >> x;

  vector<int> a(n + 1, 0);
  for (int i = 0; i <= n; ++i) {
    cin >> a[i];
  }

  int dp[x + 1][2];
  for (int i = 0; i < x + 1; ++i) {
    dp[i][0] = dp[i][1] = MOD;
  }

  dp[0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    int multiple = a[i - 1], single = multiple >> 1;
    for (int j = x; j >= multiple; --j) {
      dp[j][1] = min(dp[j - multiple][0] + 1, dp[j][1]);
    }
    for (int j = x; j >= single; --j) {
      dp[j][0] = min(dp[j - single][0] + 1, dp[j][0]);
      dp[j][1] = min(dp[j - single][1] + 1, dp[j][1]);
    }
  }

  int ans = min(dp[x][0], dp[x][1]);
  cout << (ans >= MOD ? -1 : ans) << '\n';

  return;
}

int main() {
  Solve();
  return 0;
}
