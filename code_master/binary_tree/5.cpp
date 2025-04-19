#include <queue>
#include <vector>

#include "tree_node.h"

using namespace std;

// leetcode 102. 二叉树的层序遍历

// URL: https://leetcode-cn.com/problems/binary-tree-level-order-traversal/

class Solution {
 public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      int size = q.size();
      vector<int> level;
      for (int i = 0; i < size; i++) {
        TreeNode* node = q.front();
        q.pop();
        if (node != nullptr) {
          level.push_back(node->val);
          q.push(node->left);
          q.push(node->right);
        }
      }
      if (!level.empty()) {
        result.push_back(level);
      }
    }
    return result;
  }
};

int main() {
  Solution solution;
  return 0;
}
