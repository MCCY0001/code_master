#include <algorithm>

#include "tree_node.h"

using namespace std;

// leetcode 111. 二叉树的最小深度

// URL: https://leetcode.cn/problems/maximum-depth-of-binary-tree/

class Solution {
 public:
  int minDepth(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    }
    // if (root->left == nullptr && root->right == nullptr) {
    //   return 1;
    // }
    if (root->left != nullptr && root->right == nullptr) {
      return 1 + minDepth(root->left);
    }
    if (root->left == nullptr && root->right != nullptr) {
      return 1 + minDepth(root->right);
    }
    return 1 + min(minDepth(root->left), minDepth(root->right));
  }
};
int main() {
  Solution solution;
  return 0;
}
