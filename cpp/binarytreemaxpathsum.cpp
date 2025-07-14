#include <algorithm>
#include <climits>
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
  int max{INT_MIN};
  int maxPathSum(TreeNode *root) {
    maxBranchSum(root);
    return this->max;
  }

  int maxBranchSum(TreeNode *node) {
    if (node == nullptr) {
      return 0;
    }

    int left = maxBranchSum(node->left);
    int right = maxBranchSum(node->right);
    this->max = std::max(this->max, node->val + left + right);

    int sum = std::max(left, right) + node->val;
    return std::max(sum, 0);
  }
};
