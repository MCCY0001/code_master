#include <algorithm>

#include "tree_node.h"

using namespace std;

// leetcode 110. 平衡二叉树

// URL: https://leetcode.cn/problems/balanced-binary-tree/

class Solution {
 public:
  int getHeight(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    }
    return max(getHeight(root->left), getHeight(root->right)) + 1;
  }
  bool isBalanced(TreeNode* root) {
    if (root == nullptr) {
      return true;
    }
    return abs(getHeight(root->left) - getHeight(root->right)) <= 1 &&
           isBalanced(root->left) && isBalanced(root->right);
  }
};
int main() {
  Solution solution;
  return 0;
}
