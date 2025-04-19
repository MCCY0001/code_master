#ifndef _TREE_NODE_H_
#define _TREE_NODE_H_

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  explicit TreeNode() : val(0), left(nullptr), right(nullptr) {}
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  explicit TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

#endif  // _TREE_NODE_H_
