#include <iostream>
using namespace std;
#include <stack>
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
    int kthSmallest(TreeNode* root, int k) {
        int n = 0;
        return dfs(root, n , k);
    }
private:
    int dfs(TreeNode* root, int& n, int k){
        if(!root) return -1;
        int left = dfs(root->left, n, k);
        if(left != -1) return left;
        n++;
        if(n == k) return root->val;
        int right = dfs(root->right, n, k);
        if(right != -1) return right;
    }
};

class InOrderSolution{
public:
    int kthSmallest(TreeNode* root, int k){
        stack<TreeNode*> dfs;
        dfs.push(root);
        while(!dfs.empty()){
            while(root){
                dfs.push(root);
                root = root->left;
            }
            root = dfs.top();
            dfs.pop();
            k--;
            if(k== 0) return root->val;
            root = root->right;
        }
    }
};