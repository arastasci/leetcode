
//  Definition for singly-linked list.
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 // my original solution
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int prev = 0;
        ListNode dummy = ListNode();
        
        ListNode *nodeP = &dummy;
        while(l1 && l2){
            int sum = l1->val + l2->val + prev;
            ListNode *node = new ListNode( sum % 10);
            
            prev = sum / 10;
            l1 = l1->next;
            l2 = l2->next;
            nodeP->next = node;
            nodeP = nodeP->next;
        }
        if(l1){
            while(l1){
                int sum = l1->val+prev;
                ListNode *node = new ListNode((sum)%10);
                prev = sum / 10;
                nodeP->next = node;
                nodeP = nodeP->next;
                l1 = l1->next;
            }
        }
        else if(l2){
            while(l2){
                int sum = l2->val+prev;
                ListNode *node = new ListNode((sum)%10);
                prev = sum / 10;
                nodeP->next = node;
                nodeP = nodeP->next;
                l2 = l2->next;
            }
        }
        if(prev > 0){
            ListNode *node = new ListNode(prev);
            nodeP->next = node;
        } 
        return dummy.next;
    }
};

// the G's solution
class Solution2 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *resultHead, *node;
        resultHead = node = new ListNode;
        int carry = 0;
        
        while (l1 || l2 || carry) {
            node = node->next = new ListNode;
            
            node->val += l1 ? l1->val : 0;
            node->val += l2 ? l2->val : 0;
            node->val += carry;
            
            carry = node->val > 9 ? 1 : 0;
            if (carry) node->val %= 10;
            
            l1 = l1 ? l1->next : 0;
            l2 = l2 ? l2->next : 0;
        }
        
        return resultHead->next;
    }
};