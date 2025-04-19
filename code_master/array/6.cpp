#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  /**
   * @brief 生成一个 n x n 的矩阵，矩阵元素按顺时针螺旋顺序填充从 1 到 n^2
   * 的数字
   *
   * 此函数使用模拟螺旋填充的方法，从矩阵的左上角开始，按顺时针方向依次填充数字。
   * 每次填充完一行或一列后，更新边界，继续下一个方向的填充，直到所有元素都被填充。
   *
   * @param n 矩阵的大小，即矩阵的行数和列数
   * @return vector<vector<int>> 填充好的 n x n 矩阵
   */
  vector<vector<int>> generateMatrix(int n) {
    // 初始化上边界
    int top = 0;
    // 初始化下边界
    int bottom = n;
    // 初始化左边界
    int left = 0;
    // 初始化右边界
    int right = n;
    // 创建一个 n x n 的矩阵，初始值都为 0
    vector<vector<int>> result(n, vector<int>(n));
    // 初始化要填充的数字为 1
    int num = 1;
    // 当要填充的数字小于等于 n * n 时，继续填充
    while (num <= n * n) {
      // 从左到右填充上边界
      for (int i = left; i < right; i++) {
        // 将当前数字填充到矩阵的上边界
        result[top][i] = num++;
      }
      // 上边界下移
      top++;
      // 从上到下填充右边界
      for (int i = top; i < bottom; i++) {
        // 将当前数字填充到矩阵的右边界
        result[i][right - 1] = num++;
      }
      // 右边界左移
      right--;
      // 从右到左填充下边界
      for (int i = right - 1; i >= left; i--) {
        // 将当前数字填充到矩阵的下边界
        result[bottom - 1][i] = num++;
      }
      // 下边界上移
      bottom--;
      // 从下到上填充左边界
      for (int i = bottom - 1; i >= top; i--) {
        // 将当前数字填充到矩阵的左边界
        result[i][left] = num++;
      }
      // 左边界右移
      left++;
    }
    // 返回填充好的矩阵
    return result;
  }
};

int main() {
  Solution solution;
  int n = 3;
  vector<vector<int>> result = solution.generateMatrix(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << result[i][j] << " ";
    }
    cout << endl;
  }
}