#include <iostream>

using namespace std;
// ACM 模式

void reverse(string& s, int left, int right) {
  while (left < right) {
    swap(s[left], s[right]);
    ++left;
    --right;
  }
}

int main() {
  int n;
  string s;
  cin >> n;
  cin >> s;
  int len = s.size();
  reverse(s, 0, len - 1);
  reverse(s, 0, n - 1);
  reverse(s, n, len - 1);
  cout << s << endl;
  return 0;
}
