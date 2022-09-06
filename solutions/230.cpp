#include <iostream>
using namespace std;
#include <stack>
#include <queue>

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
        if(++n == k) return root->val;
        int right = dfs(root->right, n, k);
        if(right != -1) return right;
        return -1;
    }
};

class HeapSolution {
public:
    int kthSmallest(TreeNode* root, int k) {
        queue<TreeNode*> bfs;
        priority_queue<int> heap;
        bfs.push(root);
        
        while (!bfs.empty()) {
            TreeNode* node = bfs.front();
            bfs.pop();
            
            heap.push(node->val);
            if (heap.size() > k)
                heap.pop();
            
            if (node->left)
                bfs.push(node->left);
            if (node->right)
                bfs.push(node->right);
        }
        
        return heap.top();
    }
};
class InOrderSolution{
public:
    int kthSmallest(TreeNode* root, int k){
        stack<TreeNode*> dfs;
        
        while(root || !dfs.empty()){
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
        return 0;
    }
};