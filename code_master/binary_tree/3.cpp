#include <stack>
#include <vector>

#include "tree_node.h"

using namespace std;

// leetcode 94. 二叉树的中序遍历(迭代)
// leetcode 144. 二叉树的前序遍历(迭代)
// leetcode 145. 二叉树的后序遍历(迭代)
// 后序遍历：左右根，可以由先序遍历(根左右，然后调换成根右左，再整体reverse即可)

// URL_ADDRESS// https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
// URL_ADDRESS//
// https://leetcode-cn.com/problems/binary-tree-preorder-traversal/
// URL_ADDRESS//
// https://leetcode-cn.com/problems/binary-tree-postorder-traversal/

class Solution {
 public:
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> stk;
    while (root || !stk.empty()) {
      while (root) {
        stk.push(root);
        root = root->left;
      }
      root = stk.top();
      stk.pop();
      res.push_back(root->val);
      root = root->right;
    }
    return res;
  }
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> stk;
    while (root != nullptr || !stk.empty()) {
      while (root != nullptr) {
        res.push_back(root->val);
        stk.push(root);
        root = root->left;
      }
      root = stk.top();
      stk.pop();
      root = root->right;
    }
    return res;
  }
  // vector<int> postorderTraversal(TreeNode* root) {
  //   vector<int> res;
  //   stack<TreeNode*> stk;
  //   while (root != nullptr || !stk.empty()) {
  //     while (root != nullptr) {
  //       res.push_back(root->val);
  //       stk.push(root);
  //       root = root->right;
  //     }
  //     root = stk.top();
  //     stk.pop();
  //     root = root->left;
  //   }
  //   reverse(res.begin(), res.end());
  //   return res;
  // }
  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> stk;
    TreeNode* visited;
    while (root || !stk.empty()) {
      while (root) {
        stk.push(root);
        root = root->left;
      }
      root = stk.top();
      stk.pop();
      if (!root->right || root->right == visited) {
        res.push_back(root->val);
        visited = root;
        root = nullptr;
      } else {
        stk.push(root);
        root = root->right;
      }
    }
    return res;
  }
};

int main() {
  Solution solution;
  return 0;
}
