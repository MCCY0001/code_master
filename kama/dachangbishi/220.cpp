#include <algorithm>
#include <iostream>
#include <set>

using ll = long long;
using namespace std;

void Solve() {
  ll n, k;
  cin >> n >> k;

  string s;
  cin >> s;

  ll ans = 0;
  set<char> char_set;
  ll remaining_count = 0;

  for (int i = 0; i < s.size(); ++i) {
    char current_char = s[i];
    char_set.insert(current_char);
    ++i;

    if (s[i] == '(') {
      i++;
    }

    ll count = 0;
    while (i < s.size() && isdigit(s[i])) {
      count = count * 10 + s[i] - '0';
      ++i;
    }

    int types = char_set.size();

    ll needed = max((k + types - 1) / types - remaining_count, 1ll);
    if (count >= needed) {
      count -= needed;
      ++ans;

      char_set.clear();

      ans += count / k;
      count = count % k;

      if (count > 0) {
        char_set.insert(current_char);
      }
      remaining_count = count;
    } else {
      remaining_count += count;
    }
  }
  cout << (ans == 0 ? -1 : ans) << '\n';
  return;
}

int main() {
  Solve();
  return 0;
}