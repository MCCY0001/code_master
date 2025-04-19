#include <queue>

#include "tree_node.h"

using namespace std;

// leetcode 101. 对称二叉树

// URL: https://leetcode.cn/problems/symmetric-tree/description/

// class Solution {
//  public:
//   bool compare(TreeNode* left, TreeNode* right) {
//     if (left == nullptr && right == nullptr) {
//       return true;
//     } else if (left == nullptr && right != nullptr) {
//       return false;
//     } else if (left != nullptr && right == nullptr) {
//       return false;
//     } else {
//       return left->val == right->val && compare(left->left, right->right) &&
//              compare(left->right, right->left);
//     }
//   }

//   bool isSymmetric(TreeNode* root) {
//     return root == nullptr || compare(root->left, root->right);
//   }
// };

class Solution {
 public:
  bool check(TreeNode* u, TreeNode* v) {
    queue<TreeNode*> q;
    q.push(u);
    q.push(v);
    while (!q.empty()) {
      u = q.front();
      q.pop();
      v = q.front();
      q.pop();
      if (!u && !v) {
        continue;
      }
      if ((!u || !v) || (u->val != v->val)) {
        return false;
      }
      q.push(u->left);
      q.push(v->right);
      q.push(u->right);
      q.push(v->left);
    }
    return true;
  }
  bool isSymmetric(TreeNode* root) { return check(root, root); }
};

int main() {
  Solution solution;
  return 0;
}
