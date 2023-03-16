/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        return bfs(root);
    }
    bool bfs(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        bool hasNull = false;
        while(!q.empty()){
            
            TreeNode* cur = q.front();
            q.pop();
            if(cur == nullptr){
                hasNull = true;
                continue;
            }
            else if(hasNull) return false; 
    
            q.push(cur->left);
            q.push(cur->right);
        }
        return true;
        
    }
};