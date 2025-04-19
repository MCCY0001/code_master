#include <utility>

#include "tree_node.h"

using namespace std;

// leetcode 102. 翻转二叉树

// URL: https://leetcode-cn.com/problems/binary-tree-level-order-traversal/

class Solution {
 public:
  TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) {
      return root;
    }
    swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);
    return root;
  }
};

int main() {
  Solution solution;
  return 0;
}
