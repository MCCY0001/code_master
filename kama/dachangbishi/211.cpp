#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

void Solve() {
  int n;
  cin >> n;

  unordered_set<string> id_set;
  vector<string> ans;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    if (id_set.find(s) == id_set.end()) {
      id_set.insert(s);
      ans.push_back(s);
    } else
      continue;
  }

  for (auto s : ans) {
    cout << s << '\n';
  }
}

int main() {
  Solve();
  return 0;
}