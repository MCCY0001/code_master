#include "tree_node.h"

// leetcode 222. 完全二叉树的节点个数

// URL: https://leetcode.cn/problems/count-complete-tree-nodes/description/

class Solution {
 public:
  // 通解：
  // int countNodes(TreeNode* root) {
  //   if (root == nullptr) {
  //     return 0;
  //   }
  //   return 1 + countNodes(root->left) + countNodes(root->right);
  // }
  int countNodes(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    }
    TreeNode* left = root;
    TreeNode* right = root;
    int left_depth = 0, right_depth = 0;
    while (left) {
      left = left->left;
      left_depth++;
    }
    while (right) {
      right = right->right;
      right_depth++;
    }
    if (left_depth == right_depth) {
      return (2 << (left_depth - 1)) - 1;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
  }
};
int main() {
  Solution solution;
  return 0;
}
