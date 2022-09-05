#include <iostream>
#include <vector>
#include <queue>
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> levels;
        dfs(levels, root);
        return levels;
    }
private:
    void dfs(vector<int>& levels, TreeNode* root, int level = 0){
        if(!root) return;
        if(levels.size() == level){
            levels.push_back(root->val);
        }
        dfs(levels, root->right, level + 1);
        dfs(levels, root->left, level + 1);
        
    }
};

class BFSSolution{
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<int> levels;
        while(!q.empty()){
            int qLength = q.size();
            TreeNode* node;
            cout<< node->val;
            for(int i=0; i < qLength; i++){
                
                TreeNode* idfk = q.front();
                q.pop();
                if(idfk){
                    node = idfk;
                    q.push(idfk->left);
                    q.push(idfk->right);
                }
                
            }
            if(node)
            levels.push_back(node->val);
        }
        return levels;
    }
};