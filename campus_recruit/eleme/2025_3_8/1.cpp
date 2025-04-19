#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  cin >> s;
  int result = 1;
  int count_0 = 0, count_1 = 0;
  for (char ch : s) {
    if (ch == '0') {
      result += count_1;
      count_0++;
    } else {
      result += count_0;
      count_1++;
    }
  }
  cout << result;
}