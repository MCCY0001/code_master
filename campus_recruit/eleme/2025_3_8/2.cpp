#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 定义 5x5 ASCII 码表示的 0-9 数字
const vector<vector<string>> s0 = {
    {"#000#", "#0#0#", "#0#0#", "#0#0#", "#000#"},
    {"##0##", "##0##", "##0##", "##0##", "##0##"},
    {"#000#", "###0#", "#000#", "#0###", "#000#"},
    {"#000#", "###0#", "#000#", "###0#", "#000#"},
    {"#0#0#", "#0#0#", "#000#", "###0#", "###0#"},
    {"#000#", "#0###", "#000#", "###0#", "#000#"},
    {"#000#", "#0###", "#000#", "#0#0#", "#000#"},
    {"#000#", "###0#", "###0#", "###0#", "###0#"},
    {"#000#", "#0#0#", "#000#", "#0#0#", "#000#"},
    {"#000#", "#0#0#", "#000#", "###0#", "#000#"}};

void Change(vector<string>& matrix) {
  for (string col : matrix) {
    for (char ch : col) {
      if (ch > '0' && ch <= '9') {
        ch = '0';
      }
    }
  }
  return;
}

int main() {
  int n;
  cin >> n;
  string result = "";
  vector<string> matrix;
  for (int i = 0; i < n; ++i) {
    matrix.clear();
    for (int j = 0; j < 5; ++j) {
      string col;
      cin >> col;
      matrix.push_back(col);
    }
    Change(matrix);
    for (int digit = 0; digit < s0.size(); ++digit) {
      if (s0[digit] == matrix) {
        result += static_cast<char>(digit + '0');
      }
    }
  }
  cout << result << endl;
}