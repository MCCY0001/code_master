#include <iostream>

using namespace std;

class Solution {
 public:
  int getBitSum(int n) {
    int sum = 0;
    while (n != 0) {
      sum += (n % 10) * (n % 10);
      n /= 10;
    }
    return sum;
  }
  /*
  无论是快乐数还是不快乐数，最终都会进入 4 → 16 → 37 → 58 → 89 → 145 → 42 → 20 →
  4 的循环中。
  因此，我们可以使用“快慢指针”思想找出循环：“快指针”每次走两步，“慢指针”
  每次走一步，当二者相等时，即为一个循环周期。此时，判断是不是因为 1
  引起的循环，是的话就是快乐数，否则不是快乐数。
  */
  bool isHappy(int n) {
    int slow = n, fast = n;
    do {
      slow = getBitSum(slow);
      fast = getBitSum(fast);
      fast = getBitSum(fast);
    } while (slow != fast);
    return slow == 1;
  }
};

int main() {
  Solution solution;
  cout << solution.isHappy(19) << endl;
  return 0;
}