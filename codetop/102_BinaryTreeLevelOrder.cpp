#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> result;
    if (root == nullptr) {
      return result;
    }

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      int n = q.size();
      vector<int> level;
      for (int i = 0; i < n; ++i) {
        level.push_back(q.front()->val);
        if (q.front()->left) {
          q.push(q.front()->left);
        }
        if (q.front()->right) {
          q.push(q.front()->right);
        }
        q.pop();
      }
      result.push_back(level);
      level.clear();
    }
    return result;
  }
};