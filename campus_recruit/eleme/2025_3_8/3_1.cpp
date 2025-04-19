/**
 * 问题描述：
 * 小柒最近想到了一个好玩的游戏，这个游戏一共会进行 n
 * 轮，每一轮，小柒会从下方三种操作中选择一种进行：
 * 1. 在黑板上写一个整数 x；
 * 2. 擦去黑板上的一个整数 x（此操作之前保证黑板上有这个整数）；
 * 3. 询问黑板上哪个数字与整数 x 的异或值最大（若黑板上此时没有数字，则输出
 * -1）。 对于每一次询问操作，需要输出对应的答案。
 *
 * 代码思路：
 * 1. 使用一个 std::set 来模拟黑板，存储整数。
 * 2. 使用一个 std::map 来映射操作码（1, 2, 3）到对应的操作函数。
 * 3. 在 main 函数中读取输入的操作轮数 n
 * 和每一轮的操作码及整数，然后根据操作码执行相应的操作。
 */

#include <functional>
#include <iostream>
#include <map>
#include <set>

using namespace std;
static set<int> blackboard;
static map<int, function<void(int)>> ops_map = {
    {1, [](int x) { blackboard.insert(x); }},
    {2, [](int x) { blackboard.erase(x); }},
    {3, [](int x) {
       if (blackboard.empty()) {
         cout << "-1\n";
       } else {
         int max_xor = -1;
         int result = -1;
         for (int num : blackboard) {
           int xor_val = x ^ num;
           if (xor_val > max_xor) {
             max_xor = xor_val;
             result = num;
           }
         }
         cout << result << '\n';
       }
     }}};

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> operations;
  while (n--) {
    int op, x;
    cin >> op >> x;
    operations.push_back({op, x});
  }
  for (auto operation : operations) {
    int op = operation.first;
    int x = operation.second;
    ops_map[op](x);
  }
  return 0;
}