#include <iostream>
using namespace std;
// Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root, nullptr, nullptr);
    }
private:
    bool dfs( TreeNode* node, TreeNode* left, TreeNode* right){
        if(!node) return true;
        if((left && node->val <= left->val) || (right && node->val >= right->val)) return false;
        return dfs(node->left, left, node) && dfs(node->right, node, right);
    }
};