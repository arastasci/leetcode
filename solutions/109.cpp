/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        return binarySplit(head, nullptr);
    }
    TreeNode* binarySplit(ListNode* head, ListNode* tail){
        if(head == tail) return nullptr;
        if(head->next == tail) return new TreeNode(head->val);
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != tail 
        && fast->next != tail){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* middle = slow; 
        TreeNode* root = new TreeNode(middle->val);
        root->left = binarySplit(head, middle);
        root->right = binarySplit(middle->next, tail);
        return root;
    }

};