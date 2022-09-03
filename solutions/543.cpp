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
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return diameter;
    }
private:
    int diameter = 0;
    int dfs(TreeNode* root){
        if(root == nullptr) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        int z = left + right;
        if( z > diameter) diameter = z;
        return 1 + max(left, right);
    }
};