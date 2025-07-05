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
  bool isValidBST(TreeNode *root) {
    if (root == nullptr) {
      return true;
    }

    bool left = root->left == nullptr ||
                root->left->val < root->val && isValidBST(root->left);
    bool right = root->right == nullptr ||
                 root->right->val < root->val && isValidBST(root->right);

    return left && right;
  }
};
