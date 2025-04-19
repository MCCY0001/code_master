#include <algorithm>

#include "tree_node.h"

using namespace std;

// leetcode 104. 二叉树的最大深度

// URL: https://leetcode.cn/problems/maximum-depth-of-binary-tree/

class Solution {
 public:
  int maxDepth(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    }
    int left_max_length = maxDepth(root->left);
    int right_max_length = maxDepth(root->right);
    return max(left_max_length, right_max_length) + 1;
  }
};

int main() {
  Solution solution;
  return 0;
}
