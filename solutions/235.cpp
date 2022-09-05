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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root->val > q->val && root->val > p->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        else if(root->val < q->val && root->val < p->val){
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
};

class Solution2{

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* cur = root;
        while(cur){
            if(p->val > cur->val && q->val > cur->val){
                cur = cur->right;
            }
            else if(p->val < cur->val && q->val < cur->val){
                cur = cur->left;
            }
            else return cur;
        }
        return nullptr;
    }
};