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
    int goodNodes(TreeNode* root) {
        int goodNodeCount = 0;
        dfs(root, root->val, goodNodeCount);
        return goodNodeCount;
    }
private:
    void dfs(TreeNode* node, int prevMax, int& goodNodeCount){
        if(node == nullptr){
            return;
        }
        int maximum;
        if(node->val >= prevMax){
            maximum = node->val;
            goodNodeCount++;
        }
        else{
            maximum = prevMax;
        }
        dfs(node->left, maximum, goodNodeCount);
        dfs(node->right, maximum, goodNodeCount);
    }
};

class SecondSolution{
public:
    int goodNodes(TreeNode* root){
        return dfs(root, root->val);
    }
private:
    int dfs(TreeNode* node, int maxVal){
        if(!node) return 0;
        int res;
        if(node->val >= maxVal){
            res = 1;
        }else
        {
            res = 0;
            maxVal = node->val;
        }
        res += dfs(node->left, maxVal);
        res += dfs(node->right, maxVal);
        return res;
    }
};