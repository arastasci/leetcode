/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution2 // the better one
{
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left != nullptr && right != nullptr) return root;
        return left != nullptr ? left : right;

    }
}

class Solution // my original solution (absolute worst possible solution ever) 
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> ps;
        stack<TreeNode*> qs;
        bool pFound = false;
        bool qFound = false;
        dfs(ps, root, p, pFound);
        dfs(qs, root, q, qFound);
        set<TreeNode*> s;
        while (!ps.empty()){
            s.insert(ps.top());
            ps.pop();
        }
        while(!qs.empty()){
            if(s.find(qs.top()) != s.end()){
                return qs.top();
            }
            qs.pop();
        }
        return nullptr;

    }

    void dfs(stack<TreeNode*>& st, TreeNode* root,TreeNode* node, bool& isFound){ 
        if(root == nullptr || isFound) return;
        st.push(root);
        if(root->val == node->val) {
            isFound = true;
            return;
        }
        dfs(st, root->left, node, isFound);
        dfs(st, root->right, node, isFound);
        if(isFound) return;
        st.pop();

        
    }
};

