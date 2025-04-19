#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
// 知识盲区：Fenwick Tree
class FenwickTree {
 public:
  FenwickTree(int size) : n(size), tree(n + 2, 0) {}

  void Update(int idx, int delta = 1) {
    ++idx;
    while (idx <= n) {
      tree[idx] += delta;
      idx += idx & -idx;
    }
  }

  int Query(int idx) {
    ++idx;
    int res = 0;
    while (idx > 0) {
      res += tree[idx];
      idx -= idx & -idx;
    }
    return res;
  }

 private:
  int n;
  vector<int> tree;
};

void Solve() {
  int n;
  cin >> n;

  vector<int> arr(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  vector<int> left_count(n);
  unordered_map<int, int> count_map;
  for (int i = 0; i < n; ++i) {
    ++count_map[arr[i]];
    left_count[i] = count_map[arr[i]];
  }

  vector<int> right_count(n);
  count_map.clear();
  for (int j = n - 1; j >= 0; --j) {
    ++count_map[arr[j]];
    right_count[j] = count_map[arr[j]];
  }

  // int ans = 0;
  // for (int i = 0; i < n; ++i) {
  //   for (int j = i + 1; j < n; ++j) {
  //     if (left_count[i] > right_count[j]) {
  //       ++ans;
  //     }
  //   }
  // }

  FenwickTree ft(n);
  long long ans = 0;
  for (int j = 0; j < n; ++j) {
    int x = right_count[j];
    int count = j - ft.Query(x);
    ans += count;

    ft.Update(left_count[j]);
  }

  cout << ans << '\n';
}

int main() {
  Solve();
  return 0;
}