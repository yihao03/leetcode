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

    queue<TreeNode *> odd;
    queue<TreeNode *> even;

    odd.push(root);

    bool isOdd = true;

    while (true) {
      vector<int> level;
      queue<TreeNode *> *currentQueue;
      queue<TreeNode *> *nextQueue;
      if (isOdd) {
        currentQueue = &odd;
        nextQueue = &even;
      } else {
        currentQueue = &even;
        nextQueue = &odd;
      }

      if (currentQueue->empty()) {
        break;
      }

      while (!currentQueue->empty()) {
        TreeNode *curr = currentQueue->front();
        currentQueue->pop();
        level.push_back(curr->val);
        if (curr->left) {
          nextQueue->push(curr->left);
        }
        if (curr->right) {
          nextQueue->push(curr->right);
        }
      }

      result.push_back(level);
      isOdd = !isOdd;
    }

    return result;
  }
};
