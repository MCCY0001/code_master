#include <iostream>
#include <stack>

using namespace std;

void Solve() {
  int n;
  cin >> n;

  char* str = new char[n];
  for (int i = 0; i < n; ++i) {
    cin >> str[i];
  }

  int ans = 0;
  stack<char> stk;
  for (int i = 0; i < n; ++i) {
    if (!stk.empty() && stk.top() == str[i]) {
      stk.pop();
      ++ans;
    }
    stk.push(str[i]);
  }

  cout << ans << '\n';
}

int main() {
  Solve();
  return 0;
}