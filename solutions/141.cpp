// Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
  };
 
 #include <iostream>
 #include <unordered_set>
 // using sets, not optimal.
class Solution1 {
public:
    bool hasCycle(ListNode *head) {
        std::unordered_set<ListNode*> set;
        while(head){
            if(set.find(head->next) != set.end()){
                return true;
            }
            set.insert(head);
            head = head->next;
        }
        return false;
    }
};

class Solution2{
public:
    bool hasCycle(ListNode *head){
        if(head == nullptr) return false;
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast->next != nullptr && fast->next->next != nullptr ){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                return true;
            }
        }
        return false;
    }
};