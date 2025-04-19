#include <iostream>

using namespace std;
// ACM 模式
int main() {
  string s;
  while (cin >> s) {
    int s_old_index = s.size() - 1;
    int count = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] >= '0' && s[i] <= '9') {
        ++count;
      }
    }
    s.resize(s.size() + count * 5);
    int s_new_index = s.size() - 1;
    while (s_old_index >= 0) {
      if (s[s_old_index] >= '0' && s[s_old_index] <= '9') {
        s[s_new_index--] = 'r';
        s[s_new_index--] = 'e';
        s[s_new_index--] = 'b';
        s[s_new_index--] = 'm';
        s[s_new_index--] = 'u';
        s[s_new_index--] = 'n';
      } else {
        s[s_new_index--] = s[s_old_index];
      }
      --s_old_index;
    }
    cout << s << endl;
  }
  return 0;
}
