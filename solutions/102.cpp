#include <iostream>
#include <queue>
#include <vector>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> nodes;
        vector<vector<int>> levels;
        nodes.push(root);
        
        while(!nodes.empty()){
            vector<int> level;
            int queueLength = nodes.size();
            for(int i = 0; i < queueLength; i++){
                TreeNode* node = nodes.front();
                nodes.pop();
                if(node){
                    nodes.push(node->left);
                    nodes.push(node->right);
                    level.push_back(node->val);
                }
            }
            if(!level.empty())
            levels.push_back(level);
        }   
        return levels;
    }
};

class Recursive{
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        recursion(root);
        return levels;
    }
private:
    vector<vector<int>> levels;
    void recursion(TreeNode* root, int level = 0){
        if(!root) return;
        if(levels.size() == level) levels.push_back({});
        levels[level].push_back(root->val);
        recursion(root->left, level + 1);
        recursion(root->right, level + 1);
    }
};