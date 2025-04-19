#include <vector>

#include "tree_node.h"

using namespace std;

// leetcode 94. 二叉树的中序遍历(递归)
// leetcode 144. 二叉树的前序遍历(递归)
// leetcode 145. 二叉树的后序遍历(递归)

// URL_ADDRESS// https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
// URL_ADDRESS//
// https://leetcode-cn.com/problems/binary-tree-preorder-traversal/
// URL_ADDRESS//
// https://leetcode-cn.com/problems/binary-tree-postorder-traversal/

class Solution {
 public:
  void inorder(TreeNode* root, vector<int>& res) {
    if (root == nullptr) return;
    inorder(root->left, res);
    res.push_back(root->val);
    inorder(root->right, res);
  }
  void preorder(TreeNode* root, vector<int>& res) {
    if (root == nullptr) return;
    res.push_back(root->val);
    preorder(root->left, res);
    preorder(root->right, res);
  }
  void postorder(TreeNode* root, vector<int>& res) {
    if (root == nullptr) return;
    postorder(root->left, res);
    postorder(root->right, res);
    res.push_back(root->val);
  }
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    inorder(root, res);
    return res;
  }
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    preorder(root, res);
    return res;
  }
  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    postorder(root, res);
    return res;
  }
};

int main() {
  Solution solution;
  return 0;
}
