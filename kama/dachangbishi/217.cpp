#include <iostream>
#include <vector>

using namespace std;

void Solve() {
  int n, m;
  cin >> n >> m;
  vector<string> matrix(n);
  for (int i = 0; i < n; ++i) {
    cin >> matrix[i];
  }

  int ans = 0;

  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < m - 1; ++j) {
      int a = matrix[i][j] - '0';
      int b = matrix[i][j + 1] - '0';
      int c = matrix[i + 1][j] - '0';
      int d = matrix[i + 1][j + 1] - '0';
      if (a + b + c + d == 2) {
        ++ans;
      }
    }
  }
  cout << ans << '\n';
}

int main() {
  Solve();
  return 0;
}